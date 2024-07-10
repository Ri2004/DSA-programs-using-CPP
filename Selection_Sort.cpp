/* Selection Sort

Algorithm:

1) In selection sort at first minimum element is found from whole array and then need to swap it with element present at 0 index, if swapping required. 

2) After that we need to find minimum element from index 1 to n-1, then that element will be swap with element present in index 1, if swapping required.

3) After that we need to find minimum element from index 2 to n-1 then that element will be swap with element present in index 2, if swapping required and so on upto the end of the array

4) In every pass one index is less i.e. in pass 1 we start from index 0 and in pass 2 we start from index 1

5) In first pass smallest element is get placed at its correct position and every pass smallest elements one by one gets placed at its position.
*/

#include<iostream>
using namespace std;

void swap(int &n1, int &n2)
{
    int t;
    t = n1;
    n1 = n2;
    n2 = t;
}

int main()
{
    int *ptr, n, i, j, min;

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
             << "Array Elements after Sorting" << endl;
             
        for (i = 0; i < n; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if(ptr[min] > ptr[j])
                    min = j;
            }
            if(min != i)
                swap(ptr[i], ptr[min]);
        }
        for (i = 0; i < n; i++)
            cout << ptr[i] << " ";
    }

    delete[] ptr;

    return 0;
}