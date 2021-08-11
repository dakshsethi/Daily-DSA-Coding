/*
Sorting an array using Insertion Sort Technique

Time Complexity:
    Best = Ω(N)
    Average = Θ(N^2)
    Worst = O(N^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void insertionSort(int arr[], int n) {
    int key;
    for(int i=1; i<n; i++) {
        key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
  
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array: ";
    printArray(arr, n);
    
    insertionSort(arr, n);
    cout<<"\nSorted Array: ";
    printArray(arr, n);
    
    return 0;
}