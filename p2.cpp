#include <iostream>

using namespace std;

class Bst
{
    private:
        struct node
        {
            int val;
            node* l;
            node* r;
        }*root;
        
    public:
        Bst()
        {
            root = NULL;
        }
        node* newnode(int val)
        {
            node* t = new node;
            t->val = val;
            t->l = NULL;
            t->r = NULL;
            return t;
        }
        void preorder();
        void display(node* t);
        void create();
        void longest_path();
        int trav(node *t, int h);
        void min_data();
        void swap();
        void swapm(node *t);
        void search();
};

void Bst :: min_data()
{
    node *t = root;
    while (t->l != NULL)
    {
        t = t->l;
    }
    cout << "--> " << t->val;
}

void Bst :: search()
{
    int key;
    cout << "\nEnter the Numebr to be searched: ";
    cin >> key;
    node *t = root;
    while (t != NULL)
    {
        if (t->val == key)
        {
            cout << "\nFound..!";
            return;
        }

        else if (key < t->val)
        {
            t = t->l;
        }

        else
        {
            t = t->r;
        }
    }

    cout << "Not found..!";
    return;
}

void Bst :: display(node *t)
{
    if (t == NULL)
    {
        return;
    }

    cout << " ---> " << t->val;
    display(t->l);
    display(t->r);
}

void Bst :: preorder()
{
    display(root);
    cout << "\n";
}

void Bst :: create()
{
    int key;
    do
    {
        int val;
        cout << "Enter Value: ";
        cin >> val;
        node* t = newnode(val);
        if (root == NULL)
        {
            root = t;
        }

        else
        {
            node* p = root;
            while (p != NULL)
            {
                if (val < p->val)
                {
                    if (p->l == NULL)
                    {
                        p->l = t;
                        break;
                    }
                    p = p->l;
                }
                else
                {
                    if (p->r == NULL)
                    {
                        p->r = t;
                        break;
                    }
                    p = p->r;
                }
            }
        }


        cout << "Do u want to Add more nodes..?(1/0): ";
        cin >> key;
    } while (key == 1);
}

void Bst :: longest_path()
{
    cout << "---> " << trav(root, 0) << "\n";
}


int Bst :: trav(node *t, int h)
{
    if (t == NULL)
    {
        return h - 1;
    }

    int leftH = trav(t->l, h + 1);
    int rightH = trav(t->r, h + 1);

    return (leftH > rightH) ? leftH : rightH;
}

void Bst ::swap()
{
    swapm(root);
    cout << "\nNodes have been swapped..!\n";
    preorder();
}

void Bst :: swapm(node *t)
{
    if (t == NULL)
    {
        return;
    }
    node *tmp = t->l;
    t->l = t->r;
    t->r = tmp;

    swapm(t->l);
    swapm(t->r);
}


void menu()
{
    int key;
    Bst b;
    do
    {    
        cout << "\nMenu-->";
        cout << "\n1.Insert nodes in the Tree";
        cout << "\n2.Find the longest path";
        cout << "\n3.Find Minimum Value";
        cout << "\n4.Swap roles and display";
        cout << "\n5.Search";
        cout << "\n6.Display";
        int ch;
        cout << "\nEnter ur choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                b.create();
                break;
            case 2:
                b.longest_path();
                break;
            case 3:
                b.min_data();
                break;
            case 4:
                b.swap();
                break;
            case 5:
                b.search();
                break;
            case 6:
                b.preorder();
                break;
        }

        cout << "Do u want to Continue..?(1/0)";
        cin >> key;
    } while (key == 1);
}

int main()
{
    menu();
    return 0;
}