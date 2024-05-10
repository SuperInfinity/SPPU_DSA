#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class files
{
    private:
        struct student
        {
            int r;
            string name;
            string add;
            char div;
        }s;

    public:
        void create();
        void display();
        void delete_it();
        void search();
};

void files :: create()
{
    fstream f("student.data", ios :: out | ios :: binary);
    int key;
    cout << "\nEnter student data:-->\n";
    do
    {
        cout << "\nEnter name: ";
        cin >> s.name;
        cout << "\nEnter roll no: ";
        cin >> s.r;
        cout << "\nEnter address: ";
        cin  >> s.add;
        cout << "\nEnter division: ";
        cin >> s.div;

        f.write((char*)&s, sizeof(s));

        cout << "\nWant to continue? (1/0): ";
        cin >> key;
    } while (key == 1);
    f.close();
}

void files :: display()
{
    cout << "\n---------displaying data---------\n";
    fstream f("student.data", ios :: in | ios :: binary);
    while (f.read((char*)&s, sizeof(s)))
    {
        cout << s.name << " " << s.r << " " << s.add << " " << s.div << "\n------------------\n";
    }
    f.close();
}

void files :: delete_it()
{
    int key;
    cout << "Enter the roll no u want to delete: ";
    cin >> key;
    fstream f1("student.data", ios :: in | ios :: binary);
    fstream f2("1.data", ios :: out | ios :: binary);
    bool f = false;
    while (f1.read((char*)&s, sizeof(s)))
    {
        if (s.r == key)
        {
            f = true;
            continue;
        }
        else
        {
            f2.write((char*)&s, sizeof(s));
        }
    }

    if (f)
    {
        cout << "\nDeleted\n";
    }
    else
    {
        cout << "\nData Not Found\n";
    }
    remove("student.data");
    rename("1.data", "student.data");

    f1.close();
    f2.close();
    return;
}

void files :: search()
{
    int key;
    fstream f("student.data", ios :: in | ios :: binary);
    cout << "Enter the roll no of student u want to search ";
    cin >> key;

    while (f.read((char*)&s, sizeof(s)))
    {
        if (key == s.r)
        {
            cout << "\nFound..!\n";
            cout << s.name << " " << s.r << " " << s.add << " " << s.div << "\n------------------\n";
            return;
        }
    }

    cout << "Not found..!\n";
}



int main()
{
    files f;
    f.create();
    f.display();
    f.delete_it();
    f.display();
    f.search();
}