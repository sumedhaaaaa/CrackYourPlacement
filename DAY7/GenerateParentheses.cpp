class Solution {
public:
    void generatedParenthesis(vector<string>&result, string current,int open,int close,int n)
    {
        if(current.length()==2*n)
        {
            result.push_back(current);
            return;
        }

        if(open<n)
        {
            generatedParenthesis(result,current+"(",open+1,close,n);
        }
        if(open>close)
        {
            generatedParenthesis(result,current+")",open,close+1,n);
        }

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generatedParenthesis(result, "", 0, 0, n);
        return result;
    }
};
