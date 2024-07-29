class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& subset,set<vector<int>>&st)
    {
          
           
        if (index >= nums.size()) 
        {
        if (st.find(subset) == st.end()) //element not being present
        {
            st.insert(subset);
        }
        return;
    }
          
            subset.push_back(nums[index]);
            solve(nums,index+1,subset,st);
            subset.pop_back();
           
           solve(nums,index+1,subset,st);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> subset;
       
         set<vector<int>>st;
         sort(nums.begin(),nums.end());
        solve(nums,0,subset,st);
        vector<vector<int>>result(st.begin(), st.end());
        return result;   
        
    }
};
