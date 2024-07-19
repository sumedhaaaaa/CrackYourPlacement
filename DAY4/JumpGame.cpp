2 3 1 1 4
0 1 2 3 4
the array elements denote the number of jumps that can be taken from that index.Therefore the number of jumps should be <= the array element. This can be solved using recursion like the problem of climbing stairs.But this will
give a tle so we use dp.

  int c=i+nums[i];               
ie,c=0+2=2(max reach)
for calculating the number of jumps would be [i+nums[i]] we did "i+" because we have to see whether we can reach the last index from i+1 to the jump.

class Solution {
public:
    bool solve(vector<int>&nums,int i,vector<int>& dp)
    {
        int n=nums.size();
        if(i==n-1)
            return true;
        if(nums[i]==0)
            return false;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int c=i+nums[i];
        for(int ind=i+1;ind<=c;ind++)
        {
            if(ind<n && solve(nums,ind,dp))
                return dp[i]=true;
        }
        
        
        
        return dp[i]=false;
            
    }
    
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums, 0,dp);
    }
    
    
};
