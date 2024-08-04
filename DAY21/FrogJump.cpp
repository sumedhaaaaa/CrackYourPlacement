class Solution {
public:
    unordered_map<int,int>mp;
    
    bool solve(int i,int k,vector<int>&stones,vector<vector<int>>&dp)
    {
        
        //int i=mp[ind];
        if(i==stones.size()-1)
            return true;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        bool k0=false,k1=false,k2=false;
        
        if(k>1 && mp.find(stones[i]+k-1)!=mp.end())
            k0=solve(mp[stones[i]+k-1],k-1,stones,dp);
        
        //This finds the index of the stone located at position ind + k - 1 in the stones vector.
        
        if(mp.find(stones[i]+k)!=mp.end())
            k1=solve(mp[stones[i]+k],k,stones,dp);
        
        if(mp.find(stones[i]+k+1)!=mp.end())
            k2=solve(mp[stones[i]+k+1],k+1,stones,dp);
        
        dp[i][k]=(k0|| k1 || k2);
        return dp[i][k];
    }
    
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        int k=1;
        if(stones[1]-stones[0]!=1)
            return false;
        
        for(int i=0;i<stones.size();i++)
            mp.insert({stones[i],i});
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(1,1,stones,dp);
    }
};
