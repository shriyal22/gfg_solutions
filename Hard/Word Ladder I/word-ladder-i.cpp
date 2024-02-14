//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<pair<string, int>> q;
        
        q.push({startWord, 1});
        st.erase(startWord);
        
        while(!q.empty()){
            string wd = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(wd==targetWord) return cnt;
            
            for(int i=0;i<wd.size();i++){
                char org = wd[i];
                for(char ch='a'; ch<='z';ch++){
                    wd[i] = ch;
                    
                    if(st.find(wd) != st.end()){
                        q.push({wd, cnt+1});
                        st.erase(wd);
                    }
                }
                wd[i] = org;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends