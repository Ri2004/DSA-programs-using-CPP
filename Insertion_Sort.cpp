#include<iostream>
using namespace std;

int main()
{
    int n, i, j, *ptr, min;
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

        cout << endl;
        for (i = 1; i < n; i++)
        {
            min = ptr[i];
            j = i - 1;
            while (j >= 0 && ptr[j] > min)
            {
                ptr[j + 1] = ptr[j];
                ptr[j] = min;
                j--;
            }
        }

        cout << "Array Elements after Sorting" << endl;
        for (i = 0; i < n; i++)
            cout << ptr[i] << " ";
    }

    delete[] ptr;

    return 0;
}