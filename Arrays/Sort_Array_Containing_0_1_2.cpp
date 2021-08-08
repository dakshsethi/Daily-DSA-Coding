/*
Sort an Array consisting of 0s, 1s and 2s
Without using any sorting algorithm.

NOTE: This is a variation of "Dutch national flag problem".

1. Simple Aproach : 2Times Array Traversal, Time Complexity = O(2*N)
2. Dividing Array into 3 parts : 1 Time Array Traversal, Time Complexity = O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;

//TimeComplexity: 0(N)
void specialSort_012(int arr[], int n) {
    int low=0, mid=0, high=n-1;
    while(mid <= high) {
        switch(arr[mid]) {
            case 0: swap(arr[low++], arr[mid++]);
                    break;
            case 1: mid++;
                    break;
            case 2: swap(arr[high--], arr[mid++]);
                    break;
        }
    }
}

//TimeComplexity: O(2*N)
void sort_012(int arr[], int n) {
    int c0=0, c1=0, c2=0;
    for(int i=0; i<n; i++)
        if(arr[i] == 0) ++c0;
        else if(arr[i] == 1) ++c1;
        else ++c2;
       
    int k=0;
    for(int i=0; i<c0; i++) arr[k++]=0;
    for(int i=0; i<c1; i++) arr[k++]=1;
    for(int i=0; i<c2; i++) arr[k++]=2;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {0, 1, 2, 0, 2, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    sort_012(arr, n);
    cout<<"\nSorted Array: ";
    printArray(arr, n);

    int arr1[] = {0, 1, 2, 0, 2, 2, 1, 0};
    specialSort_012(arr1, n);
    cout<<"\nSpecialSorted Array: ";
    printArray(arr1, n);

    return 0;
}