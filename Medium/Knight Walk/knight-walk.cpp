//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
	    
	    if(KnightPos == TargetPos) return 0;
	    int ans = 1e9;
	    vector<vector<int>> dist(N+1, vector<int>(N+1, INT_MAX));
	    
	    dist[KnightPos[0]][KnightPos[1]] = 0;
	    queue<pair<int,pair<int, int>>> q;
	    q.push({0,{KnightPos[0], KnightPos[1]}});
	    while(!q.empty()){
	        int steps = q.front().first;
	        int i = q.front().second.first;
	        int j = q.front().second.second;
	        q.pop();
	        
	        for(int k=0;k<8;k++){
	            int r = i + dr[k];
	            int c = j + dc[k];
	            if(r>=1 && c>=1 && r<=N && c<=N && dist[r][c] > 1 + steps){
	                if(r==TargetPos[0] && c==TargetPos[1]) return steps+1;
	                dist[r][c] = steps+1;
	                q.push({steps+1, {r, c}});
	            }
	        }
	    }
	    
	    return -1;
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends