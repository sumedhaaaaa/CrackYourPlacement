class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=a.size()-1;
        int j=b.size()-1;
        
        int carry=0;
        
        while(i>=0 || j>=0)
        {
            int sum=carry;
            
            if(i>=0)
                {
                    sum+=a[i]-'0';
                    i--;
                }
            
            if(j>=0)
                {
                    sum+=b[j]-'0';
                    j--;
                }
            
           carry = sum / 2;
            sum = sum % 2;
            
            ans.push_back(sum+'0');
            
        }
        if (carry) {
            ans.push_back(carry + '0');
        }
           reverse(ans.begin(), ans.end());

        return ans;
    }
};
