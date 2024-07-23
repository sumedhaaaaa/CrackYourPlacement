class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int n=needle.size();
        int j=0;

        int k;
        for(int i=0;i<haystack.size();i++)
        {
            
            if(haystack[i]==needle[0])
            {
            int c=0;
              for(int j=0;j<needle.size();j++)
              {
                  if(haystack[i+j]==needle[j])
                      c++;
                  else
                      break;
              }
             if(c==n)
                return i;
            }
           
        }
        
        return -1;
    }
};
