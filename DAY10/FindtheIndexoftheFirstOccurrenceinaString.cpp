class Solution {
public:
    const int MOD = 1e9 + 7;
    long long hashvalue(string string, long long radix, long long m)
    {
        long long ans=0,factor=1;
        for(long long i=m-1;i>=0;i--)
        {
            ans+=((string[i]-'a')*factor)%MOD;
            factor=(factor*radix)%MOD;
        }
        return ans%MOD;
    }
    int strStr(string haystack, string needle) {
        long long n=haystack.length(), m=needle.length();
        
        long long radix=26, maxweight=1;
        for(long long i=1;i<=m;i++)
            maxweight=(maxweight*radix)%MOD;
        
        long long hashneedle=hashvalue(needle,radix,m);
        long long hashHay; // declare hashHay here
        
        for(long long i=0;i<=n-m;i++)
        {
            if(i==0)
                hashHay=hashvalue(haystack,radix,m);
            else
                hashHay=((hashHay*radix)%MOD -((haystack[i-1]-'a')*maxweight)%MOD +(haystack[i+m-1]-'a')+MOD)%MOD;
            
            if(hashneedle==hashHay)
            {
                for(long long j=0;j<m;j++)
                {
                    if(needle[j]!=haystack[i+j]) // fix the index here
                        break;
                    if(j==m-1)
                        return i;
                }
            }
        }
        return -1; // move this line outside the loop
    }
};
