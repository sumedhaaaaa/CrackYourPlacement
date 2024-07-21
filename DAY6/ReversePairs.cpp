class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) 
    {
            vector<int> temp; // temporary array
            int left = low;      // starting index of left half of arr
            int right = mid + 1;   // starting index of right half of arr
        while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                }
                else {
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while (left <= mid) {
                temp.push_back(arr[left]);
                left++;
            }

            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }

            for (int i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
        }
    
    int count(vector<int>&nums,int low,int mid,int high)
    {
        int right=mid+1;
        int c=0;
        for(int i=low;i<=mid;i++)
        {
        while(right<=high && (long long)nums[i]>2LL*nums[right])
                right++;
            c+=right-(mid+1);
        }
        return c;
    }
    
    int mergesort(vector<int>&nums,int low,int high)
    {
        int c=0;
        if(low>=high)
            return c;
        int mid=low+(high-low)/2;
        
        c+=mergesort(nums,low,mid);
        c+=mergesort(nums,mid+1,high);
        c+=count(nums,low,mid,high);
        merge(nums,low,mid,high);
        
        return c;
    }
    
    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
