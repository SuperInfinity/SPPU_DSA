#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class file 
{
    private :

        struct student
        {
            string name;
            int roll;
            char division;
            string address;
        } s;

    public :
    
        void create();
        void display();
        void delete_it();
        void search();
    
};

void file :: create()
{
    fstream f("students.data" , ios :: out | ios :: binary );
    int key;
    cout << "\n STUDENTS DATA \n";

    do
    {
        cout << "STUDENTS NAME : ";
        cin >> s.name;

        cout << "STUDENTS ROLLNO : ";
        cin >> s.roll;

        cout << "STUDENTS DIVISION : ";
        cin >> s.division;

        cout << "STUDENTS ADDRESS : ";
        cin >> s.address;

        f.write((char* ) &s , sizeof(s));

        cout << "\nDO YOU WANT TO CONTINUE  (1/0) : \n";
        cin >> key;

    } while (key == 1);
    f.close();
    
}

void file :: display()
{
    fstream f ("students.data" , ios :: in | ios :: binary );
    cout << " \n DISPLAYING DATA : \n";

    while (f.read((char* ) &s , sizeof (s)))
    {
        cout << s.name << " " << s.roll << " " << s.division << " " << s.address << "" ; 
    }
    f.close();
}

int main()
{
    file f;
    int ch;
    
    do
    {
        cout << "ENTER YOUR CHOICE : ";
        cin >> ch;

        switch (ch){
            
            case 1:
            f.create();
            break;

            case 2:
            f.display();
            break;

                

        }


    }while(ch != 2);
    return 0;
    

}