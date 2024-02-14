//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int f(int idx, int W, int val[], int wt[], vector<vector<int>> &dp){
        
        if(idx==0){
            if(W>=wt[0]){
                return (int)(W/wt[0])*val[0];
            } else return 0;
        }
        if(dp[idx][W] != -1) return dp[idx][W];
        int pick = (int)-1e9;
        if(wt[idx] <= W){
            pick = val[idx] + f(idx, W-val[idx], val, wt, dp);
        }
        int notPick = f(idx-1, W, val, wt, dp);
        
        return dp[idx][W] = max(pick, notPick);
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1, 0));
        
        for(int w=0;w<=W;w++){
            dp[0][w] = val[0]*(int)(w/wt[0]);
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notPick = dp[i-1][j];
                int pick = -1e9;
                if (wt[i] <= j) {
                  pick = val[i] + dp[i][j - wt[i]];
                }
    
                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[N-1][W];
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends