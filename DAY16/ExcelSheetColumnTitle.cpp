class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber>0)
        {
            columnNumber--;
            int remainder=columnNumber%26;
            res+=remainder + 'A' ;
            columnNumber=columnNumber/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
