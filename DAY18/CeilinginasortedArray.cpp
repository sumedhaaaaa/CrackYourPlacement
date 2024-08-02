class Solution {
public:
    int firstoccur(vector<int>&nums,int low,int high,int target)
    {
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
    
    int lastoccur(vector<int>&nums,int low,int high,int target)
    {
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        int first=firstoccur(nums,low,high,target);
        int last=lastoccur(nums,low,high,target);
        
        return {first,last};
    }
};
