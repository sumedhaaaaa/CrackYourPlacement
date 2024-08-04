class Solution {
public:
    void merge(int low,int mid,int high,vector<pair<int, int>>& arr,vector<int>& count)
    {
        vector<pair<int,int>>temp(high-low+1);
        
        int left=low;
        int right=mid+1;
        int k = 0;
        
        while(left<=mid && right<=high)
        {
            if(arr[left].first <= arr[right].first)
            {
                temp[k++] = arr[left];
                count[arr[left].second] += right - mid - 1;
                left++;
            }
            else
            {
                temp[k++] = arr[right];
                right++;
            }
        }
        
        while(left<=mid)
        {
            temp[k++] = arr[left];
            count[arr[left].second] += high - mid;
            left++;
        }
        
        while(right<=high)
        {
            temp[k++] = arr[right];
            right++;
        }
        
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
    }
    
    void divide(int low,int high,vector<pair<int, int>>& arr, vector<int>& count)
    {
        if(low < high)
        {
            int mid=low+(high-low)/2;
            divide(low, mid, arr, count);
            divide(mid+1, high, arr, count);
            merge(low, mid, high, arr, count);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
	    vector<pair<int, int>> arr;
	    for(int i = 0; i < n; i++)
	    {
	        arr.push_back({nums[i], i});
	    }	    
	    vector<int> count(n, 0);	    
	    divide(0, n - 1, arr, count);
	    return count;
    }
};
