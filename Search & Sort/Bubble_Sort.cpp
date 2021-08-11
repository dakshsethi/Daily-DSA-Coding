/*
Sorting an array using Bubble Sort Technique

Time Complexity:
    Best = Ω(N)
    Average = Θ(N^2)
    Worst = O(N^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(int arr[], int n, int type) {
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(type == 0) {
                if(arr[i]>arr[j])
                    swap(arr[i], arr[j]);
            }
            else {
                if(arr[i]<arr[j])
                    swap(arr[i], arr[j]);
            }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {2, 9, -8, 10, 3, 8, 0, 12, -20, 17, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array: ";
    printArray(arr, n);

    //Type = 0, For Ascending Sort
    bubbleSort(arr, n, 0);
    cout<<"\nAscending Sort: ";
    printArray(arr, n);

    //Type = 1, For Descending Sort
    bubbleSort(arr, n, 1);
    cout<<"\nDescending Sort: ";
    printArray(arr, n);
    
    return 0;
}