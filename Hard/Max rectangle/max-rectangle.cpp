//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    int f(int row[], int m){
        stack<int> st;
        int maxArea=-1;
        for(int i=0;i<=m;i++){
            while(!st.empty() && (i==m || row[st.top()] >= row[i])){
                int h = row[st.top()];
                st.pop();
                int w = (st.empty())?i:i-st.top()-1;
                maxArea = max(maxArea, h*w);
            }
            st.push(i);
        }
        
        return maxArea;
        
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = f(M[0], m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0) M[i][j] += M[i-1][j];
            }
            area = max(area, f(M[i], m));
        }
        
        return area;
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends