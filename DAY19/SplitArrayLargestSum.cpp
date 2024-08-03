int countArray(vector<int> &nums, int sub) {
        int part = 1;
        long long group = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (group + nums[i] <= sub)
                group += nums[i];
            else {
                part++;
                group = nums[i];
            }
        }
        return part;
    }
class Solution {
public:
    
    int splitArray(vector<int>& nums,int k) {  
        if (k > (nums.size()))
            return -1;

        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0)+start;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int number = countArray(nums,mid);

            if (number > k)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }
};


