#include <iostream>
#include <vector>

using namespace std;

void maxheap(vector<int>& arr, int i)
{
    int p = (i - 1) / 2;
    int c = i;
    while (p >= 0 && arr[p] < arr[c])
    {
        swap(arr[p], arr[c]);
    }

}

void minheap(vector<int>& arr, int i)
{
    int p = (i - 1) / 2;
    int c = i;
    while (p >= 0 && arr[p] > arr[c])
    {
        swap(arr[p], arr[c]);
    }
}

void init()
{
    vector <int> arr;
    int n, m;
    cout << "Enter number of students: ";
    cin >> n;

    arr.resize(n, 0);

    cout << "\nEnter Marks: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark of student " << i + 1 << " : ";
        cin >> m;
        arr[i] = (m);
    }
    int key;
    do
    {
        int ch;
        cout << "\n------------MENU---------------\n1.MAXHEAP\n2.MINHEAP\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                maxheap(arr, i);
            }
            cout << "\n ---> " << arr[0];
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                minheap(arr, i);
            }
            cout << "\n ---> " << arr[0];
        default:
            break;
        }

        cout << "do u want to continue?(1/0): ";
        cin >> key;
    } while (key == 1);
}

int main()
{
    init();
}