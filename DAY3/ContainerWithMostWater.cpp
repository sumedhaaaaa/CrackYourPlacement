class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxarea=INT_MIN;
        while(i<j)
        {
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=w*h;
            
            if(area>maxarea)
                maxarea=area;
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return maxarea;
    }
};
