/*
Sorting an array using Selection Sort Technique

Time Complexity:
    Best = Ω(N^2)
    Average = Θ(N^2)
    Worst = O(N^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void selectionSort(int arr[], int n) {
    int pos=0;
    for(int i=0; i<n-1; i++) {
        int min = arr[i];
        for(int j=i+1; j<n; j++)
            if(arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        swap(arr[i], arr[pos]);
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

    selectionSort(arr, n);
    cout<<"\nSorted Array: ";
    printArray(arr, n);
    
    return 0;
}