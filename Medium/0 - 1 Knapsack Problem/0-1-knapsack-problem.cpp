//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int n, int idx, vector<vector<int>> &dp){
        if(idx==0) {
            if(wt[idx]<=w) return val[idx];
            return 0;
        }
        if(dp[idx][w] != -1) return dp[idx][w];
        int pick = 0;
        if(wt[idx] <= w){
            pick = val[idx] + solve(w-wt[idx], wt, val, n, idx-1, dp);
        }
        int notPick = solve(w, wt, val, n, idx-1, dp);
        
        return dp[idx][w] = max(pick, notPick);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
       return solve(w, wt, val, n, n-1, dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends