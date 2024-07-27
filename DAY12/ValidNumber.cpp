class Solution {
public:
    bool isNumber(string s) {
        bool digitflag=false;
        bool signflag=false;
        bool dotflag=false;
        bool eflag=false;
        
        int c=0;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            
            
            //fordigits
            if(isdigit(ch))
                digitflag= true;
            
            //forsign'-/+'
            else if(ch=='-' || ch=='+')
            {
                if(c==2)
                    return false;
                
                if(i>0 && (s[i-1]!='e' && s[i-1]!='E'))
                    return false;
                
                if(i==s.size()-1)
                    return false;
                
                c++;
            }
            
            //fordots
            else if(ch=='.')
            {
                if(eflag || dotflag)
                    return false;
                
                if(i==s.size()-1 && !digitflag)
                    return false;
                
                dotflag=true;
            }
            
            //foreE
            else if(ch=='e' || ch=='E')
            {
                if(eflag || !digitflag || i==s.size()-1)
                    return false;
                
                eflag=true;
            }
            
            else
                return false;
        }
        return true;
    }
};
