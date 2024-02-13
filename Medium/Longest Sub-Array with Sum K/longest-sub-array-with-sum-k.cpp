//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the functin
        int sum = 0;
        int len = 0;
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            if(sum==k) len = i+1;
            if(mp.find(sum-k) != mp.end()){
                len = max(len, i-mp[sum-k]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        
        
        
        // FOR POSITIVE ELEMENTS ARRAY
        // while(j<n){
        //     sum+=a[j];
        //     while(sum>k){
        //         sum-=a[i];
        //         i++;
        //     }
        //     if(sum == k){
        //         len = max(len, j-i+1);
        //     }
        //     j++;
        // }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends