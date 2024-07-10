#include<iostream>
using namespace std;

int linearSearch(int arr[], int length, int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int *ptr, n, i, targetKey, found;
    cout << "Enter size of Array" << endl;
    cin >> n;

    ptr = new int[n];

    if(ptr)
    {
        cout << "Enter array Elements" << endl;
        for (i = 0; i < n; i++)
            cin >> ptr[i];

        cout << "Enter Element which you want to find in array" << endl;
        cin >> targetKey;

        found = linearSearch(ptr, n, targetKey);

        if(found > -1)
            cout << targetKey << " is Found in array" << endl;
        else
            cout << targetKey << " is not Found in array" << endl;
    }

    return 0;
}