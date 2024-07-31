class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int product1=nums[n-3]*nums[n-1]*nums[n-2];
        int product2=nums[0]*nums[1]*nums[n-1];
        //the case where two negative numbers and the largest number can be greater than the other case
        
        return max(product1,product2);
    }
};
