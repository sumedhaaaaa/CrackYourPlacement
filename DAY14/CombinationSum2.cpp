class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& current, int target, int start) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) 
        {
            if(i>start && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
                current.push_back(candidates[i]);
                solve(candidates, ans, current, target - candidates[i], i+1); //the new value of target changes with target-arr[i]
                current.pop_back();
            }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        solve(candidates, ans, current, target, 0);
        return ans;
    }
};
