#include<iostream>
using namespace std;

void swap(int &n, int &n1)
{
    n = n + n1;
    n1 = n - n1;
    n = n - n1;
}

int main()
{
    int *ptr, n, i, r;

    cout << "Enter size of array" << endl;
    cin >> n;

    ptr = new int[n];
    if(ptr)
    {
        cout << "Enter array Elements" << endl;
        for (i = 0; i < n; i++)
            cin >> ptr[i];

        cout << "Array Elements Before Sorting" << endl;
        for (i = 0; i < n; i++)
            cout << ptr[i] << " ";

        cout << endl
             << "Array Elements After Sorting" << endl;
        for (r = 1; r < n; r++)
        {
            for (i = 0; i < n - r; i++)
            {
                if(ptr[i] > ptr[i+1])
                    swap(ptr[i], ptr[i + 1]);
            }
        }

        for (i = 0; i < n; i++)
            cout << ptr[i] << " ";
    }

    delete[] ptr;

    return 0;
}