#include <iostream>

using namespace std;

class Btt
{
    private:
        struct node
        {
            int val;
            node *l;
            node *r;
            bool lf;
            bool rf;
        }*root, *head;
    
    public:
        Btt()
        {
            root = NULL;
            head = newnode(0);
            head->l = head;
            head->r = root;
        }
        node* newnode(int val)
        {
            node* t = new node;
            t->val = val;
            t->l = NULL;
            t->r = NULL;
            t->lf = false;
            t->rf = false;
            return t;
        }
        void create();
        void display();
        void postorder();
};

void Btt :: create()
{
    int ans;
    do
    {    
        int val;
        cout << "Enter Value: ";
        cin >> val;
        if (root == NULL)
        {
            root = newnode(val);
            root->l = head;
            root->r = head;
        }

        else
        {
            node *p = root;
            node *t = newnode(val);
            while (p != NULL)
            {    
                if (val < p->val)
                {
                    if (!(p->lf))
                    {
                        t->l = p->l;
                        p->l = t;
                        p->lf = true;
                        t->r = p;
                        break;
                    }
                    p = p->l;
                }
                else
                {
                    if (!(p->rf))
                    {
                        t->r = p->r;
                        p->r = t;
                        p->rf = true;
                        t->l = p;
                        break;
                    }
                    p = p->r;
                }
            }
        }
        cout << "\nDo u Want to insert more nodes?(1/0): ";
        cin >> ans;
    } while (ans == 1);
}


void Btt :: postorder()
{
    node *t = root;
    while (t != head)
    {
        cout << " ----> " << t->val;
        if (!(t->rf))
        {
            while (!(t->lf))
            {
                if (t->l == head)
                {
                    return;
                }
                t = t->l;
            }   
            t = t->l;
        }
        else
        {
            t = t->r;
        }
    }
}

void Btt :: display()
{
    node *t = root;
    while (t != head)
    {
        cout << " ----> " << t->val;
        if (!(t->lf))
        {
            while (!(t->rf))
            {
                if (t->r == head)
                {
                    cout << endl;
                    return;
                }
                t = t->r;
            }   
            t = t->r;
        }
        else
        {
            t = t->l;
        }
    }
}


int main()
{
    Btt b;
    b.create();
    b.display();
    b.postorder();
}