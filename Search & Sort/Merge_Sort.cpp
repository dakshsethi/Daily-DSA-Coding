#include<iostream>
#include<algorithm>
using namespace std;

int * mergeTwoArrays(int as[], int bs[]) {
    int *a = as;
    int *b = bs;
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(a)/sizeof(a[0]);
    int *c = new int(n+m);
    int k = 0;
    for(int i=0, j=0; i<n && j<m;) {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else if(a[i] > b[j])
            c[k++] = b[j++];
        else {
            c[k++] = a[i++];
            c[k++] = b[j++];
        }
    }
    if(n < m) {
        for(int i = n-1; i<m;)
            c[k++] = b[i++];
    } else {
        for(int i = m-1; i<n;)
            c[k++] = a[i++];
    }

    return c;
}

int * mergeSort(int arr[], int start, int end) {
    if(start == end) {
        int *a = new int(1);
        a[0] = start;
        return a;
    }

    int mid = (start + end)/2;
    int *f1 = mergeSort(arr, start, mid);
    int *f2 = mergeSort(arr, mid+1, end);
    int *f3 = mergeTwoArrays(f1, f2);

    return f3;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[] = {7, 4, 1, 3, 6, 8, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array: ";
    printArray(arr, n);

    // mergeSort(arr, 0, n-1);
    cout<<"\nSorted Array: ";
    printArray(mergeSort(arr, 0, n-1), n);

    return 0;
}