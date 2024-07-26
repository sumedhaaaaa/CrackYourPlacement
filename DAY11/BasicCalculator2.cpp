class Solution {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        
        int n=s.size();
        stack<int>stack;
        int currnum=0;
        char ope='+';
        for(int i=0;i<n;i++)
        {
            char currchar=s[i];
            if(isdigit(currchar))
                currnum=(currnum*10)+(currchar-'0');
            
            if(!isdigit(currchar) && !isspace(currchar) || i == n - 1)
            {
                if(ope == '-')
                    stack.push(-currnum);
                
                else if(ope == '+')
                    stack.push(currnum);
                
                else if(ope=='*')
                   stack.top()*=currnum;
                
                else if(ope=='/')
                   stack.top()/=currnum;
                
                ope=currchar;
                currnum=0;
            }
        }
        int res=0;
        while(!stack.empty())
        {
            res+=stack.top();
            stack.pop();
        }
        
        return res;
    }
};
