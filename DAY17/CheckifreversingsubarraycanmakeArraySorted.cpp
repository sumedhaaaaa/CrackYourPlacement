#include <bits/stdc++.h> 
bool sortArr(int n, vector<int> &arr){
    // Write your code here.
            vector<int>temp(n);
            for(int i=0;i<n;i++)
                temp[i]=arr[i];

            sort(temp.begin(),temp.end());
            int l=0;
            int r=n-1;

            //finding the first mismatch
            for(l=0;l<n;l++)
            {
                if(temp[l]!=arr[l])
                    break;
            }

            for(r=n-1;r>=0;r--)
            {
                if(temp[r]!=arr[r])
                    break;
            }

            reverse(arr.begin() + l, arr.begin() + r + 1);

            for(int i=0;i<n;i++)
            {
                if(arr[i]!=temp[i])
                    return false;
            }
            return true;
}
