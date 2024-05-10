#include <iostream>
#include <vector>

#define MAX 9999

using namespace std;

class Graph
{
    private:
        vector<vector<int>> graph;
        int n;
    
    public:
        Graph()
        {
            cout << "Enter Number of vertices: ";
            cin >> n;
            graph.resize(n, vector<int>(n, MAX));
        }
        void create_graph();
        void floyd_w();
};


void Graph :: create_graph()
{
    int key;
    int sv, lv, cost;
    cout << "*-------USE 0-N FOR EDGES-------*";
    do 
    {
        cout << "\nEnter Starting Vertex: ";
        cin >> sv;
        cout << "\nEnter Last Vertex: ";
        cin >> lv;
        cout << "\nEnter Cost: ";
        cin >> cost;
        graph[sv][lv] = cost;
        graph[lv][sv] = cost;

        cout << "\nDo u Want to add more Edges: (1/0): ";
        cin >> key;
    } while (key == 1);
}

void Graph :: floyd_w()
{
    cout << "\nCalculating Minimum costs..!!\n";

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] > (graph[k][i] + graph[k][j]) && (i != j))
                {
                    graph[i][j] = graph[k][i] + graph[k][j];
                    graph[j][i] = graph[k][i] + graph[k][j]; 
                }
            }
        }
    }

    cout << "\nThe Minimum cost matrix is as follows: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Graph g;
    g.create_graph();
    g.floyd_w();
}