class Solution {
public:
    
    int getmax(vector<int>&nums)
    {
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>max)
                max=nums[i];
        }
        return max;
    }
    
    void countsort(vector<int>&nums,int place)
    {
        int n=nums.size();
        int count[10]={0};
        
        for(int i=0;i<n;i++)
            count[(abs(nums[i])/place)%10]++;
        
        for(int i=1;i<10;i++)
            count[i]+=count[i-1];
        
        vector<int>output(n+1);
        for(int i=n-1;i>=0;i--)
        {
            int index = (abs(nums[i]) / place) % 10;
            output[count[index] - 1] = nums[i];
            count[index]--;
        }
        
        for(int i=0;i<n;i++)
            nums[i]=output[i];
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int maximum=getmax(nums);
        
        for(int place=1;maximum/place>0;place*=10)
            countsort(nums,place);
        
        return nums;
    }
};
