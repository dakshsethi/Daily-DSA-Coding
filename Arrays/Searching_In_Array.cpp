/*
Searching in an Array

Approach:
1. Linear Search: TimeComplexity: O(N)
2. Binary Search: TimeComplexity: O(Log(N))
*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int k) {
    while(end >= start) {
        int mid = (start+end)/2;
        if(arr[mid] == k)
            return mid;
        else if(arr[mid] > k)
            return binarySearch(arr, start, mid-1, k);
        else if(arr[mid] < k)
            return binarySearch(arr, mid+1, end, k);
    }
    return -1;
}

int linearSearch(int arr[], int n, int k) {
    for(int i=0; i<n; i++)
        if(arr[i] == k)
            return i;
    return -1;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {

    int arr1[] = {3, 2, 9, 8, 10, 12, 0, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 10;

    cout<<"Array: ";
    printArray(arr1, n);
    cout<<"\nKey: "<<key;

    if(linearSearch(arr1, n, key) != -1)
        cout<<"\nIndex: "<<linearSearch(arr1, n, key);
    else
        cout<<"\nElement not present in Array";

    int arr2[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int key2 = 5;

    cout<<"\n\nArray: ";
    printArray(arr2, n);
    cout<<"\nKey: "<<key2;

    if(binarySearch(arr2, 0, m, key2) != -1)
        cout<<"\nIndex: "<<binarySearch(arr2, 0, m, key2);
    else
        cout<<"\nElement not present in Array";
    return 0;
}