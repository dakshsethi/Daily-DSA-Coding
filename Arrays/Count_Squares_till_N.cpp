/*
Count the number of perfect squares upto N

Time Complexity: O(Sqrt(N))
*/

#include<iostream>
using namespace std;

int countSquares(int n) {
    int j=1;
    for(int i=1; i<n; i=(j+1)*(j+1), j++);
    return j-1;
}

int main() {
    int n = 10;
    cout<<"Squares till "<<n<<": "<<countSquares(n);
    return 0;
}