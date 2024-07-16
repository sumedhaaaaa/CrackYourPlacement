class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int l=nums.size();
        for(int i=0;i<l-1;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            int sum=nums[i]+nums[j];
            if(sum==target)
            {
                return {i,j};
            }
            
        }
    }
        return {};
    }
};
