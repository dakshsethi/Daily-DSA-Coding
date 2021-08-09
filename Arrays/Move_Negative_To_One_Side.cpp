/*
Given an Array of both negative and positive number
Shift the negative numbers to one side.

Approach:
1. Partition Approach of Quick Sort: Time Complexity: O(N), Space Complexity: O(1)
2. Two Pointer Approach: Time Complexity: O(N), Space Complexity: O(1)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void twoPointer(int arr[], int n) {
    int left=0, right=n-1;
    
    while(left<=right)
        if(arr[left]<0 && arr[right]<0)
            left++;
        else if(arr[left]>0 && arr[right]<0)
            swap(arr[left++], arr[right--]);
        else if(arr[left]>0 && arr[right]>0)
            right--;
        else {
            left++;
            right--;
        }
}

void quickSort(int arr[], int n) {
    int j=0;
    for(int i=0; i<n; i++)
        if(arr[i] < 0) {
            if(i != j)
                swap(arr[i], arr[j]);
            j++;
        }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    quickSort(arr, n);
    cout<<"\nNegative Elements on One Side: ";
    printArray(arr, n);

    int arr1[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    twoPointer(arr, n);
    cout<<"\nTwo Pointer Approach: ";
    printArray(arr, n);

    return 0;
}