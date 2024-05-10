#include "iostream"
#include "vector"
#include "queue"
#include "map"

#define INT_MAX 999999

using namespace std;

class City
{
public:
    string name;
    vector<pair<City*, int>> neighbors;
    bool visited;
    City* parent;
    int cost;

    City(string name) : name(name), visited(false), parent(nullptr), cost(INT_MAX) {}
};

class Graph
{
public:
    map<string, City*> cities;

    void add_cities(City* city)
    {
        cities[city->name] = city;
    }

    void add_connection(City* city1, City* city2, int cost)
    {
        city1->neighbors.push_back({city2, cost});  
        city2->neighbors.push_back({city1, cost});  
    }

    void prim(City* startCity)
    {
        priority_queue<pair<int, City*>, vector<pair<int, City*>>, greater<pair<int, City*>>> pq;
        startCity->cost = 0;

        pq.push({0, startCity});

        while (!pq.empty())
        {
            City* currentCity = pq.top().second;
            pq.pop();

            if (currentCity->visited)
            {
                continue;
            }

            currentCity->visited = true;

            for (auto neighbor : currentCity->neighbors)
            {
                if (!neighbor.first->visited && neighbor.second < neighbor.first->cost) 
                {
                    neighbor.first->cost = neighbor.second;
                    neighbor.first->parent = currentCity;
                    pq.push({neighbor.second, neighbor.first}); 
                }
            } 
        }

        int mst_cost = 0;
        for (auto city : cities)
        {
            if (city.second->parent)
            {
                mst_cost += city.second->cost;
                cout << city.second->parent->name << " -> " << city.second->name << " : " << city.second->cost << endl; 
            }
        }

        cout << "Total Minimum Cost : " << mst_cost << endl;
    }
};

int main() 
{
    Graph graph;
    int n, num1, num2, cost, choice;
    string name;
    cout << "Enter number of Cities(vertices) : ";
    cin >> n;

    // I can also create vector of type City*
    City* cities[n];

    for (int i=0; i<n; i++)
    {
        cout << "Enter name of city : ";
        cin >> name;
        cities[i] = new City(name);
        graph.add_cities(cities[i]);
    }

    while (true){
        cout << "Add first and second city's vertex : ";
        cin >> num1 >> num2;
        cout << "Enter cost between these two cities : ";
        cin >> cost;
        graph.add_connection(cities[num1], cities[num2], cost);
        cout << "You want to add more connection ? (Press 1 else 0) : ";
        cin >> choice;
        if (choice == 0){
            break;
        }
    } 

    graph.prim(cities[0]);

    return 0;
}