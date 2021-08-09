/*
Find Inserction & Union of 2 Sorted Arrays

1. Union: TimeComplexity: O(N+M), SpaceComplexity: O(N)
2. Intersection: TimeComplexity: O(N+M(logN)), SpaceComplexity: O(N)
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_map<int, int> unionArrays(int arr1[], int n, int arr2[], int m) {
    unordered_map<int, int> arr;
    for(int i=0; i<n; i++)
        arr[arr1[i]]++;

    for(int i=0; i<m; i++)
        arr[arr2[i]]++;
    
    return arr;
}

unordered_set<int> intersectArrays(int arr1[], int n, int arr2[], int m) {
    unordered_set<int> arr;
    unordered_set<int> arrs;
    for(int i=0; i<n; i++)
        arrs.insert(arr1[i]);

    for(int i=0; i<m; i++)
        if(arrs.find(arr2[i]) != arrs.end())
            arr.insert(arr2[i]);
    
    return arr;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr1[] = {1, 1, 2, 2, 3, 3};
    int arr2[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Array A: ";
    printArray(arr1, n);

    cout<<"\nArray B: ";
    printArray(arr2, m);

    
    unordered_map<int, int> arr = unionArrays(arr1, n, arr2, m);
    cout<<"\nUnion of A & B: ";
    for(auto x: arr)
        cout<<x.first<<" ";

    unordered_set<int> ar = intersectArrays(arr1, n, arr2, m);
    cout<<"\nIntersection of A & B: ";
    for(auto x: ar)
        cout<<x<<" ";
}