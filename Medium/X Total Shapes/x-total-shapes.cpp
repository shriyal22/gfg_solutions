//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i =0;i< n;i++){
            for(int j =0;j< m;j++){
                if(!vis[i][j] and grid[i][j]=='X'){
                    count++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j,int n,int m){
        vis[i][j] = 1;
        int dx[] = {-1,0, 1, 0};
        int dy[] = {0,1,0,-1};
        
        for(int k = 0;k< 4;k++){
            int x= i + dx[k];
            int y= j + dy[k];
            
            if(x>=0 and y>=0 and x< n and y< m and grid[x][y]=='X' and !vis[x][y]){
                dfs(grid,vis,x,y,n,m);
            }
        }
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends