int countStudents(vector<int> &arr,int pages)
{
    int stu=1;
    long long pagesstudent=0;

    for (int i = 0; i < arr.size(); i++)
    {
        if(pagesstudent+arr[i] <= pages)
            pagesstudent+=arr[i];
        else
        {
            stu++;
            pagesstudent=arr[i];
        }
            
    }
    return stu;
}

int findPages(vector<int>& arr,int n, int m) {
    if (m>n)
        return -1;

    int start=*max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int nostu=countStudents(arr,mid);

        if(nostu > m)
            start=mid+1;
        else
            end=mid-1;

    }
    return start;
}


