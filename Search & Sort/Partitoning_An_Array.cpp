/*
Partitoning an Array

Time Complexity: O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

void partitionArray(int arr[], int n, int pivot) {
    //0 to j-1 --> <= pivot
    //j to i-1 -->  > pivot
    //i to end -->  unknown

    for(int i=0, j=0; i<n;)
        if(arr[i] <= pivot)
            swap(arr[i++], arr[j++]);
        else
            i++;
}

int main() {
    int arr[] = {7, 9, 4, 8, 3, 6, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array: ";
    printArray(arr, n);

    cout<<"\nAfter Partition: ";
    int pivot = 5;
    partitionArray(arr, n, pivot);
    printArray(arr, n);

    return 0;
}