class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        stack<int>st;
        vector<int>res;
        
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                m[st.top()]=nums2[i];
                st.pop();
            }
            
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            if(m[nums1[i]])
                res.push_back(m[nums1[i]]);
            else
                res.push_back(-1);
        }
        
        return res;
    }
};
