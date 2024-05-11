#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
    private:
        int n;
        struct node
        {
            int vertex;
            node *next;
        }*ad_list[10];

    public:
        node* newnode(int v)
        {
            node* t = new node;
            t->next = NULL;
            t->vertex = v;
            return t;
        }
        stack <int> s;
        queue <int> q;
        void create();
        void dfs();
        void bfs();
};

void Graph :: create()
{
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ad_list[i] = NULL;
    }
    int key = 0, sv, lv;
    node *t, *p;
    cout << "\n*----------USE ANALOGY FROM 0 - N----------*\n";
    do
    {
        cout << "\nEnter starting vertex: ";
        cin >> sv;
        cout << "\nEnter Last Vertex: ";
        cin >> lv;
        t = newnode(lv);
        if (ad_list[sv] == NULL)
        {
            ad_list[sv] = newnode(sv);
        }
        p = ad_list[sv];
        if (p->next == NULL)
        {
            p->next = t;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
        }

        cout << "DO u want to add more edges?(1/0): ";
        cin >> key;
    } while (key == 1);   
}


void Graph :: bfs()
{
    int sv; 
    cout << "Enter staring Vertex: ";
    cin >> sv;
    int visited[10] = {0};
    q.push(sv);
    node* t;
    while (!(q.empty()))
    {
        int n = q.front();
        q.pop();
        if (visited[n] == 0)
        {
            cout << " --> " << n;
            visited[n] = 1;
        }
        t = ad_list[n];
        while (t != NULL)
        {
            if (visited[t->vertex] == 0)
            {
                q.push(t->vertex);
            }
            t = t->next;
        }
    }

    cout << endl;
}

void Graph :: dfs()
{
    int sv, n;
    cout << "\nEnter staring vertex: ";
    cin >> sv;
    int visited[10] = {0};
    s.push(sv);
    node* t;
    while (!s.empty())
    {
        n = s.top();
        s.pop();
        if (visited[n] == 0)
        {
            cout << " --> " << n;
            visited[n] = 1;
        }
        t = ad_list[n];
        while (t != NULL)
        {
            if (visited[t->vertex] == 0)
            {
                s.push(t->vertex);
            }
            t = t->next;
        }
    }
    cout << endl;
}

int main()
{
    Graph g;
    g.create();
    g.bfs();
    g.dfs();
}