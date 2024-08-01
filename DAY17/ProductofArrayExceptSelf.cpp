class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=1;
        right[n-1]=1;
        
        for(int i=1;i<n;i++)
            left[i]=left[i-1]*nums[i-1];
        //leaving the last index calculating all the left indices
        
        for(int i=n-2;i>=0;i--)
            right[i]=right[i+1]*nums[i+1];
        //leaving the first index calculating all the right indices
        
        vector<int>res(n);
        for(int i=0;i<n;i++)
            res[i]=left[i]*right[i];
        
        return res;
    }
};
