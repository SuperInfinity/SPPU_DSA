#include <iostream>

using namespace std;

class graph
{
    private:
        int cost[100][100];
        int n;
    
    public:
        graph()
        {
            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                    cost[i][j] = -1;
                }
            }
        }
        void ini_graph();
        void min_cost();
};


void graph :: ini_graph()
{
    cout << "\nEnter number of edges: ";
    cin >> n;
    int ans, sv, lv, c;
    cout << "\n*---Use edges from 0-N---*\n";
    do
    {
        cout << "\nEnter Starting Vertex: ";
        cin >> sv;
        cout << "\nEnter Ending vertex: ";
        cin >> lv;
        cout << "\nEnter Cost: ";
        cin >> c;

        cost[sv][lv] = c;
        cost[lv][sv] = c;

        cout << "Do u wnat to add more edges?(1/0): ";
        cin >> ans;
    } while (ans == 1);
}

void graph :: min_cost()
{
    int visited[100], sv, min, ans = 0, v1, v2;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    cout << "Enter the Starting vertx: ";
    cin >> sv;
    visited[sv] = 1;

    for (int k = 0; k < n; k++)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0)
                    {
                        if (cost[i][j] < min && cost[i][j] != -1)
                        {
                            v1 = i;
                            v2 = j;
                            min = cost[i][j];
                        }
                    }
                }
            }
        }
        ans += cost[v1][v2];
        visited[v2] = 1;
    }

    cout << "\nMinimum Cost is: " << ans << endl;
}

void menu()
{
    graph g;
    g.ini_graph();
    int ch;
    do
    {    
        cout << "\n---------Menu---------\n";
        cout << "\n1.Calculate Minimum Cost: ";
        cout << "\n2.Exit";
        cout << "\nUr choice: ";
        cin >> ch;
        if (ch == 1)
        {
            g.min_cost();
        }
        else
        {
            break;
        }
    } while (ch == 1);
}

int main()
{
    menu();
}