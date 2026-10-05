class Solution {
    
    int dfs(string &s1,string &s2,int idx1,int idx2,vector<vector<int>>&dp){
        
        if(idx1<0 || idx2<0) return 0;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2] = 1+dfs(s1,s2,idx1-1,idx2-1,dp);
        
        return dp[idx1][idx2] = 0;
    }
    
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int s = s1.size();
        int t = s2.size();
        vector<vector<int>>dp(s,vector<int>(t,-1));
        int ans = 0;
        
        for(int i=0;i<s;i++){
            for(int j=0;j<t;j++){
                ans = max(ans,dfs(s1,s2,i,j,dp));
            }
        }
        
        return ans;
    }
};