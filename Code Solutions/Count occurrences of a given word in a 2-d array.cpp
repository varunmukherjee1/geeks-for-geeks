//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){

        int ans = 0;

        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[i].size() ; j++){
                
                ans += helper(mat,i,j,target,0);

            }
        }

        return ans;
    }

    int helper(vector<vector<char> > &mat,int i , int j , string target , int idx){

        int found = 0;

        if( i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size() && target[idx] == mat[i][j]){

            mat[i][j] = '?';

            if(idx == target.length()-1){
                found = 1;
            }
            else{

                found += helper(mat,i,j-1,target,idx+1);
                found += helper(mat,i,j+1,target,idx+1);
                found += helper(mat,i+1,j,target,idx+1);
                found += helper(mat,i-1,j,target,idx+1);

            }

            mat[i][j] = target[idx];
        }

        return found;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends