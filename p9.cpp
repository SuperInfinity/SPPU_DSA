#include <iostream>
#include <string>

// looks horribaly done..Oh well..wish me luck..!
using namespace std;

class BST
{
    private:
        struct node
        {
            int id;
            string title;
            node* next;
            node* down;
        }*root;
    
    public:
        BST()
        {
            root = NULL;
        }
        node* newnode(string title)
        {
            node* t = new node;
            t->next = NULL;
            t->title = title;
            t->down = NULL;
            t->id = 1;
            return t;
        }
        void create();
        void add_book();
        void add_chapter();
        void add_section();
        void add_sub_section();
        void dispaly();
};

void BST :: add_book()
{
    node* t = root;

    while (t->next != NULL)
    {
        t = t->next;
    } 
    string title;
    cout << "Enter Title of new book: ";
    cin >> title;
    t->next = newnode(title);
    int c = t->id;
    t->next->id = c + 1;
}

void BST :: add_chapter()
{
    if (root == NULL)
    {
        cout << "THere is nothing there..!\n";
        return;
    }

    node* t = root;
    int id;
    cout << "In what book u want to insert chapter?(Enter the id): ";
    cin >> id;
    bool f = false;
    while (t != NULL)
    {
        if (t->id == id)
        {
            f = true;
            break;
        }
    }

    if (f)
    {
        string name;
        cout << "Enter name of the chapter: ";    
        cin >> name;
        node *p = newnode(name);
        if (t->down == NULL)
        {
            t->down = p;
        }
        else
        {
            t = t->down;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = p;
            p->id = t->id + 1;
        }
    }
    else
    {
        cout << "Book not found..!\n";
        return;
    }
}

void BST :: create()
{
    if (root == NULL)
    {
        char id;
        string title;
        cout << "There is no book at this time.. need to create a new one..!\n";
        cout << "Enter book title\n";
        cin >> title;
        root = newnode(title);
    }
    int key;
    do
    {   
        int id;
        cout << "\nWhat do u want to add? \n";
        cout << "1.Book\n";
        cout << "2.Chapter\n";
        cout << "3.Section\n";
        cout << "4.Subsection\n";
        cin >> id;
        if (id < 1 || id > 4)
        {
            cout << "Invalid choice..!\n";
        }

        else
        {
            switch (id)
            {
            case 1:
                add_book();
                break;
            case 2:
                add_chapter();
                break;
            case 3:
                add_section();
                break;
            case 4:
                add_sub_section();
                break;
            default:
                break;
            }
        }

        cout << "\nDo u want to add more?(1/0) ";
        cin >> key;
    } while (key == 1);
    
}

void BST :: add_sub_section()
{
    if (root == NULL)
    {
        cout << "No BOOK..!\n";
        return;
    }

    node* t = root;
    int key, f = 0;
    cout << "\nIn what book is this sub_section?: ";
    cin >> key;
    while (t != NULL)
    {
        if (t->id == key)
        {
            f = 1;
            break;
        }
        t = t->next;
    }

    if (f == 1)
    {
        f = 0;
        cout << "\nIn what chapter is this sub_section?: ";
        cin >> key;
        t = t->down;
        while (t != NULL)
        {
            if (t->id == key)
            {
                f = 1;
                break;
            }
            t = t->next;
        }

        if (f == 1)
        {
            f = 0;
            cout << "\nIn what section is this subsection?: ";
            cin >> key;
            t = t->down;
            while (t != NULL)
            {
                if (t->id == key)
                {
                    f = 1;
                    break;
                }
                t = t->next;
            }

            if (f == 1)
            {
                string name;
                cout << "\nEnter name of the name of the subsecion: ";
                cin >> name;
                node *p = newnode(name);
                if (t->down == NULL)
                {
                    t->down = p;
                }
                else
                {
                    t = t->down;
                    while (t->next != NULL)
                    {
                        t = t->next;
                    }
                    t->next = p;
                    p->id = t->id + 1;
                    return;
                }
            }
        }
    }

    if (f == 0)
    {
        cout << "Not found..!\n";
        return;
    }   
}

void BST :: add_section()
{
    if (root == NULL)
    {
        cout << "No BOOK..!\n";
        return;
    }

    node* t = root;
    int key, f = 0;
    cout << "In what book is this section?: ";
    cin >> key;
    while (t != NULL)
    {
        if (t->id == key)
        {
            f = 1;
            break;
        }
        t = t->next;
    }

    if (f == 1)
    {
        f = 0;
        cout << "In what chapter is this section?: ";
        cin >> key;
        t = t->down;
        while (t != NULL)
        {
            if (t->id == key)
            {
                f = 1;
                break;
            }
            t = t->next;
        }

        if (f == 1)
        {
            string name;
            cout << "\nEnter the name of the section: ";
            cin >> name;
            node* p = newnode(name);
            if (t->down == NULL)
            {
                t->down = p;
                return;
            }
            else
            {
                t = t->down;
                while (t->next != NULL)
                {
                    t = t->next;
                }
                t->next = p;
                p->id = t->id + 1;
            }
        }
    }

    else
    {
        cout << "Not found..!\n";
        return;
    }
}

void BST :: dispaly()
{
    if (root == NULL)
    {
        cout << "No Book Present..!\n";
        return;
    }

    node* t = root;
    node* s, *ss;
    int id;
    cout << "Enter the book's id u want to disaply: ";
    cin >> id;
    bool f;
    while (t != NULL)
    {
        if (t->id == id)
        {
            f = true;
            break;
        }
        t = t->next;
    }

    if (f)
    {
        cout << " ---> " << t->title;
        if (t->down == NULL)
        {
            cout << "No chapters..!\n";
        }
        else
        {
            t = t->down;
            while (t != NULL)
            {
                cout << "Chapter: " << t->id << ":" << t->title << " --> ";
                s = t->down;
                while (s != NULL)
                {
                    cout << "Section: "<< s->id << ":" << s->title << " --> ";
                    ss = s->down;
                    while (ss != NULL)
                    {
                        cout << "Sub-Section: " << ss->id << ":" << ss->title << " ";
                        ss = ss->next;
                    }
                    cout << "\n";
                    s = s->next;
                }
                cout << "\n";
                t = t->next;
            }
            cout << "\n";
        }
    }

    else
    {
        cout << "Not Found..!\n";
    }
    
}

int main()
{
    BST b;
    b.create();
    b.dispaly();
}