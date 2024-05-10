#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

#define INT_MAX 100

using namespace std;

class City {
public:
    string name;
    vector<pair<City*, int>> neighbors;
    bool visited;
    City* parent;
    int cost;

    City(const string& name) : name(name), visited(false), parent(nullptr), cost(INT_MAX) {}
};

class Graph {
public:
    map<string, City*> cities;

    void add_city(City* city) {
        cities[city->name] = city;
    }

    void add_connection(City* city1, City* city2, int cost) {
        city1->neighbors.push_back({city2, cost});
        city2->neighbors.push_back({city1, cost});
    }

    void prim(City* start_city) {
        // Priority queue to hold cities sorted by cost
        priority_queue<pair<int, City*>, vector<pair<int, City*>>, greater<pair<int, City*>>> pq;

        // Initialize starting city
        start_city->cost = 0;
        pq.push({0, start_city});

        while (!pq.empty()) {
            City* current_city = pq.top().second;
            pq.pop();

            if (current_city->visited) {
                continue;
            }

            current_city->visited = true;

            // Update costs of neighbors
            for (auto neighbor : current_city->neighbors) {
                if (!neighbor.first->visited && neighbor.second < neighbor.first->cost) {
                    neighbor.first->cost = neighbor.second;
                    neighbor.first->parent = current_city;
                    pq.push({neighbor.second, neighbor.first});
                }
            }
        }

        // Trace minimum spanning tree (optional)
        int mst_cost = 0;
        for (auto city : cities) {
            if (city.second->parent) {
                mst_cost += city.second->cost;
                cout << city.second->parent->name << " -> " << city.second->name << ": " << city.second->cost << endl;
            }
        }

        cout << "Total minimum cost: " << mst_cost << endl;
    }
};

int main() {
    Graph graph;

    // Create cities
    City* cityA = new City("A");
    City* cityB = new City("B");
    City* cityC = new City("C");
    City* cityD = new City("D");

    // Add cities to the graph
    graph.add_city(cityA);
    graph.add_city(cityB);
    graph.add_city(cityC);
    graph.add_city(cityD);

    // Add connections between cities
    graph.add_connection(cityA, cityB, 3);
    graph.add_connection(cityA, cityC, 1);
    graph.add_connection(cityB, cityC, 3);
    graph.add_connection(cityB, cityD, 1);
    graph.add_connection(cityC, cityD, 4);
    graph.add_connection(cityA, cityD, 1);

    // Perform Prim's algorithm starting from cityA
    graph.prim(cityA);

    // Free memory
    delete cityA;
    delete cityB;
    delete cityC;
    delete cityD;

    return 0;
}