/*
Merging 2 Sorted Arrays

Time Complexity: O(N+M)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void mergeArrays(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int k = 0;
    for(int i=0, j=0; i<n && j<m;) {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if(arr1[i] > arr2[j])
            arr3[k++] = arr2[j++];
        else {
            arr3[k++] = arr1[i++];
            arr3[k++] = arr2[j++];
        }
    }
    if(n < m) {
        for(int i = n-1; i<m;)
            arr3[k++] = arr2[i++];
    } else {
        for(int i = m-1; i<n;)
            arr3[k++] = arr2[i++];
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr1[] = {2, 5, 12, 18, 20};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Array 1: ";
    printArray(arr1, n);

    int arr2[] = {7, 9, 11, 15, 25, 28, 30, 35};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"\nArray 2: ";
    printArray(arr2, n);

    int arr3[13];
    mergeArrays(arr1, n, arr2, m, arr3);
    cout<<"\nArray 3: ";
    printArray(arr3, n+m);

    return 0;
}