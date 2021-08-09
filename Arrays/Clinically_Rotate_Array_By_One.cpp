/*
Clinically Rotate an Array by 1

Time Complexity: O(N)
*/

#include<iostream>
using namespace std;

void rotateArray(int arr[], int n) {
    int temp = arr[n-1];
    for(int i=n-2; i>=-1; i--)
        if(i == -1)
            arr[0] = temp;
        else
            arr[i+1] = arr[i];
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    rotateArray(arr,n);
    cout<<"\nRotated Array: ";
    printArray(arr, n);
}