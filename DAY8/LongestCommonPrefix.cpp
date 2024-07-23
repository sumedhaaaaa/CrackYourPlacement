class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if (n == 0) return "";
        sort(strs.begin(),strs.end());
        string left=strs[0];
        string right=strs[n-1];
        string res;
        
        for(int i=0;i<left.size();i++)
        {
            if(i>=right.size() || left[i]!=right[i])
                break;
            
            res.push_back(left[i]);
        }
        return res;
    }
};
