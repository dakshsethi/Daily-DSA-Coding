#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        /*
        This is the brute-force method using the concept of 
        in-degrees and out-degress.
        If any person has the in-degree equal to n-1 and out-degree equal to 0
        this means that person is a celebrity.
            TC = O(N^2)
            SC = O(N)
        */
        int celebrityBF(vector<vector<int>> arr, int n) {
            vector<int> indeg(n,0);
            vector<int> outdeg(n,0);
            for(int i=0; i<n; i++) {
                int count = 0;
                for(int j=0; j<n; j++) {
                    if(arr[i][j] == 1) {
                        indeg[j]++;
                        outdeg[i]++;
                        
                    }
                    outdeg[i]+=count;
                }
            }

            // cout<<"ID\tInDegree\tOutDegree\n";
            for(int i=0; i<n; i++) {
                // cout<<i<<"\t"<<indeg[i]<<"\t\t"<<outdeg[i]<<endl;
                if(indeg[i] == n-1 && outdeg[i] == 0)
                    return i;
            }
            return -1;
        }
};

int main() {
    class Solution S;
    vector<vector<int>> arr = { {0,1,0},
                                {0,0,0},
                                {0,1,0} };
    if(S.celebrityBF(arr, 3) == -1)
        cout<<"No Celebrity Exists\n";
    else
        cout<<"Celebrity = "<<S.celebrityBF(arr, 3)<<endl;
}