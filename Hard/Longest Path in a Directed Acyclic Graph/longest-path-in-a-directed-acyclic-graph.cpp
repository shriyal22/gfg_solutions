//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            vector<int>adj[v];
           vector<int> dist(v,INT_MIN);
           for(int i=0; i<edges.size(); i++) {
               adj[edges[i][0]].push_back(i);
           }
           queue<int> q;
           q.push(src);
           dist[src]=0;
           while (!q.empty()) {
               int num=q.front();
               q.pop();
               for(auto x:adj[num]) {
                   int u=edges[x][0];
                   int v=edges[x][1];
                   int weight=edges[x][2];
                   
                   if(dist[num]+weight>dist[v] ) {
                       dist[v]=dist[num]+weight;
                      q.push(v);
                       
                   }
               }
           }
           return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends