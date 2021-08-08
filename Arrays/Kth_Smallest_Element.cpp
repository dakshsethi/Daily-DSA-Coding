/*
Kth Smallest Element in an Array using
Built-in sort() which works on "INTROSORT" algorithm

Time Complexity: O(N*Log(N))
*/

#include<iostream>
#include<algorithm>
using namespace std;

int Kth_Smallest_Element(int arr[], int size, int k) {
    sort(arr, arr+size);
    return arr[k-1];
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {

    int arr[7] = {10, 4, 8, 2, 5, 10, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<"Original Array: ";
    printArray(arr, n);

    cout<<endl<<k<<" smallest element: "<<Kth_Smallest_Element(arr, n, k);

    return 0;
}