class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result)
    {
          
           
            if (index>=nums.size()) 
        {
            result.push_back(subset);
            return;
        }
          
            subset.push_back(nums[index]);
            solve(nums,index+1,subset,result);
            subset.pop_back();
           
           solve(nums,index+1,subset,result);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> subset;
        vector<vector<int> > result;
        solve(nums,0,subset,result);
        return result;
    }
};
