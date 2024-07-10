#include<iostream>
using namespace std;

void swap(int &n1, int &n2)
{
    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
}

int main()
{
    int n, *ptr, i, r, flag;

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
            flag = 0;
            for (i = 0; i < n - r; i++)
            {
                if(ptr[i] > ptr[i+1])
                {
                    swap(ptr[i], ptr[i + 1]);
                    flag = 1;
                }
            }
            if(!flag)
                break;
        }
        for (i = 0; i < n; i++)
            cout << ptr[i] << " ";
    }

    return 0;
}