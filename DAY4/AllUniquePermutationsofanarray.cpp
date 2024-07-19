
class Solution {
  public:
    void solve(vector<int>&arr,int n,vector<vector<int>>&res,int i)
    {
        set<int>st;
        if(i==arr.size())
        {
            res.push_back(arr);
            return;
        }
        
        for(int j=i;j<arr.size();j++)
        {
            if (st.find(arr[j]) != st.end()) continue;
            st.insert(arr[j]);
            swap(arr[i],arr[j]);
            solve(arr,n,res,i+1);
            swap(arr[i],arr[j]);
        }
        
        //.push_back(st);
        
        
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>res;
        solve(arr,n,res,0);
        sort(res.begin(),res.end());
        return res;
    }
};



