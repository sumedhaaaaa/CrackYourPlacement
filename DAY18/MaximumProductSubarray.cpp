class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long int pro1=nums[0];
        long long int pro2=nums[0];
        long long int res=INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(pro1==0)
                pro1=1;
            else
                pro1;
            if(pro2==0)
                pro2=1;
            else
                pro2;
            
            pro1=pro1*nums[i];
            pro2=pro2*nums[n-i-1];
            
            res=max(res,max(pro1,pro2));
        }
        
        return (int)res;
    }
};
