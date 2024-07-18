class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int rightsum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<=k-1;i++)
        {
            leftsum+=cardPoints[i];
        }
        maxsum=leftsum;
        
        int right=n-1;
        for(int i=k-1;i>=0;i--)
        {
            leftsum=leftsum-cardPoints[i];
            rightsum+=cardPoints[right];
            right--;
            
            maxsum=max(maxsum,leftsum+rightsum);
        }
        
        return maxsum;
    }
};
