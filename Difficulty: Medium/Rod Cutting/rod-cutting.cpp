class Solution {
    
    int dfs(int idx,int remLen,vector<int>&price,vector<vector<int>>&dp){
        
        if(remLen==0) return 0;
        if(idx==0) return price[0]*remLen;
        
        if(dp[idx][remLen]!=-1) return dp[idx][remLen];
        
        int notTake = dfs(idx-1,remLen,price,dp);
        int take = 0;
        int rodLength = idx+1;
        if(rodLength<=remLen) take = price[idx]+dfs(idx,remLen-rodLength,price,dp);
        
        return dp[idx][remLen] = max(take,notTake);
    }
    
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return dfs(n-1,n,price,dp);
    }
};