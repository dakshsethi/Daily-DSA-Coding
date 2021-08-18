/*
Sorting an array using Quick Sort Technique

Time Complexity:
    Best = Ω(nlog(n))
    Average = Θ(nlog(n))
    Worst = O(n^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int partitionArray(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;

    while(i < j) {
        while(arr[i] <=pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pi = partitionArray(arr, start, end);
        quickSort(arr, start, pi);
        quickSort(arr, pi+1, end);
    }
}

int main() {
    int arr[] = {8, 5, 1, 3, 7, 2, 9, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    cout<<"\nASorted Array: ";
    quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}