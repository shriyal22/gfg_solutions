//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // create graph when the first letter differs between two consecutive words and 
    // then write the topo sort to get the string
    vector<int> topoSort(vector<int> adj[], int K){
        vector<int> indegree(K, 0);
        for(int i=0;i<K;i++){
            for(auto edge: adj[i]){
                indegree[edge]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            ans.push_back(t);
            
            for(auto it: adj[t]){
                if(--indegree[it]==0) q.push(it);
            }
        }
        return ans;
        
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s = dict[i];
            string t = dict[i+1];
            int len = min(s.size(), t.size());
            for(int idx=0;idx<len;idx++){
                if(s[idx] != t[idx]){
                    adj[s[idx]-'a'].push_back(t[idx]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(adj, K);
        string ans = "";
        for(auto ch: topo) ans+=char(ch+'a');
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends