class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            
            else if (!st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']'))
             {
                char ch=st.top();
                if((ch=='(' && s[i]==')') || (ch=='{' && s[i]=='}') || (ch=='[' && s[i]==']'))
                {
                    st.pop();   
                }
                else
                    return false;

            }
            else
                    return false;
           
        }
        if(!st.empty())
            return false;
        return  true;
    }
};
