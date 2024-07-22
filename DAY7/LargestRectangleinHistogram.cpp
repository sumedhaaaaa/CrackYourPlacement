class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
         vector<int> left(n);
        
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = -1;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
            }
            st.push(i);
            }
        
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
            
        
        
    }
};
