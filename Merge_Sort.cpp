#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int start = l;
    int end = mid + 1;

    int temp[r - l + 1];
    int index = 0;

    int i, j;

    for(i = start, j = end; i <= mid && j <= r;)
    {
        if(arr[i] <= arr[j])
        {
            temp[index++] = arr[i];
            i++;
        }
        
        else
        {
            temp[index++] = arr[j];
            j++;
        }
    }

    for(; i <= mid; i++)
        temp[index++] = arr[i];
    
    for(; j <= r; j++)
        temp[index++] = arr[j];
    
    for(i = l; i <= r; i++)
        arr[i] = temp[i - l];
}

void mergeSort(int arr[], int left, int right)
{
    if(left == right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);

}

int main()
{
    int arr[8] = {25, 3, 10, 12, 15, 5, 1, 10};

    mergeSort(arr, 0, 7);

    for(int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    return 0;
}