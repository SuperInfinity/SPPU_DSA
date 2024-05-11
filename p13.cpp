#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class F
{
    private:
        struct employee
        {
            int id;
            long salary;
            string name;
        }e;
        
    public:
        void create();
        void display();
        void search();
        void delete_it();
};

void F :: create()
{
    fstream f("emp.txt", ios :: out | ios :: binary);
    int key;
    string name;
    do
    {
        cout << "\nEnter name: ";
        cin >> e.name;
        cout << "\nEnter id: ";
        cin >> e.id;
        f << e.name << " " << e.id << endl;
        cout << "Continue? (1/0): ";
        cin >> key;
    } while (key == 1);
    f.close();
}

void F ::display()
{
    fstream f("emp.txt", ios :: in | ios :: binary);
    cout << "Displaying..!\n";
    while (f >> e.name >> e.id)
    {
        cout << e.name << " --> " << e.id << endl;
    }
}

int main()
{
    F f;
    f.create();
    f.display();
}