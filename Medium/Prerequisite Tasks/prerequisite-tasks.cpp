//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[n];
        vector<int> indegree(n, 0);
        queue<int> q;
        
        vector<int> ans;
        
        for(auto it: prerequisites){
            adj[it.second].push_back(it.first);
            indegree[it.first]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it: adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return ans.size() == n;
        
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends