class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
         int s=0;
         
         int i=0;
         int j=0;
        
        int new[m+n];
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
                new[s++]=nums1[i++];
        
            else
                new[s++]=nums2[j++];
            
        }
        while(i<m)
            new[s++]=nums1[i++];
        
        
        while(j<n)
            new[s++]=nums2[j++];
        
        
        for(int i=0;i<(m+n);i++)
            nums1[i]=new[i];
        
        
    }
};
