//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for(int node=0;node<n;node++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(i==j) continue;
	                else if(matrix[i][node] != -1 && matrix[node][j] != -1) {
	                    if(matrix[i][j] == -1){
	                        matrix[i][j] = matrix[i][node] + matrix[node][j];
	                    }
	                    else matrix[i][j] = min(matrix[i][j], matrix[i][node] + matrix[node][j]);
	                }
	            }
	        }
	    }
	 }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends