class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int c=0;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        for(auto &p:mp)
        {
            if(k==0)
            {
                if(p.second > 1)
                    c++;
            }
            
            else if(mp.find(p.first+k)!=mp.end())
                c++;
        }
        return c;
    }
};
