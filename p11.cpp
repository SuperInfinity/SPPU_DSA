#include <iostream>
#include <string>

using namespace std;

enum PatientType
{
    SERIOUS,
    NON_SERIOUS,
    GENERAL
};

struct patient
{
    string name;
    PatientType type;
};

class PQ
{
    private:
        patient patients[5];
        int front;
        int back;
        int size;
    
    public:
        PQ()
        {
            front = -1;
            back = -1;
            size = 5;
        }

        bool isEmpty()
        {
            return front == -1;
        }

        bool isFull()
        {
            return back == size - 1;
        }

        void enqueue()
        {
            if (isFull())
            {
                cout << "FULL..!\n";
                return;
            }

            patient p;
            string name;
            int type;
            cout << "\nEnter the Patient's name: ";
            cin >> name;
            cout << "\nEnter the Type: \n1.Serious\n2.Non-Serious\n3.General\nEnter: ";
            cin >> type;
            p.name = name;
            p.type = static_cast<PatientType>(type-1);
            back++;
            patients[back] = p;
            if (front == -1)
            {
                front++;
            }

            for (int i = back; i > front; i--)
            {
                if (patients[i].type < patients[i-1].type)
                {
                    swap(patients[i], patients[i-1]);
                }
                else
                {
                    break;
                }
            }
            cout << "Registered Successfully..!\n";
        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Already Empty..!\n";
                return;
            }
            cout << "Dequeued: " << patients[front].name << endl;
            if (front == back)
            {
                front = back = -1;
            }
            else
            {
                front++;
            }
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "EMPTY..!\n";
                return;
            }
            for (int i = front; i <= back; i++)
            {
                cout << patients[i].name << ":" << patients[i].type << "; ";
            }
        }
};

void menu()
{
    PQ p;
    int key;
    do
    {    
        cout << "\n------MENU------\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Display";
        int ch;
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                p.enqueue();
                break;
            case 2:
                p.dequeue();
                break;
            case 3:
                p.display();
                break;
            default:
                break;
        }
        cout << "\nDo u want to continue?(1/0): ";
        cin >> key;
    } while (key == 1);
}

int main()
{
    menu();
}