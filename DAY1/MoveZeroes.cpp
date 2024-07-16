class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i=0;
        int j=0;
        int c=0;
        int n=a.size();
        while(j<n)
        {
            if(a[j]==0)
                c++;
            
            else if(a[j]!=0)
            {
                swap(a[i],a[j]);
                i++;
            }
            j++;
        }
        for(int i=n-c;i>n;i--)
            a[i]=0;
    }
};
