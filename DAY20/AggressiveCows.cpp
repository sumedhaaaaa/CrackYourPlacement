bool CanWePlace(vector<int> &stalls, int dis, int k)
{
    int countcows=1;
    int last=stalls[0];
    int n=stalls.size();

    for(int i=1;i<n;i++)
    {
        if(stalls[i]-last >= dis)
        {
            countcows++;
            last=stalls[i];
        }
     if(countcows >= k)
        return true;
    }
        return false;

}


int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (CanWePlace (stalls,mid,k)==true)
        {
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return high;
}

