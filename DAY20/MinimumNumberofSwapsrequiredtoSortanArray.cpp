#include <vector>
#include <algorithm>

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int minSwaps(vector<int>& arr) {
    int c=0;
	vector<pair<int,int>>temp(arr.size());
	for(int i=0;i<temp.size();i++)
	{
		temp[i]={arr[i],i};
	}
	sort(temp.begin(),temp.end());
	for(int i=0;i<arr.size();i++)
	{
		if(i!=temp[i].second)
		{
			c++;
			swap(arr,i,temp[i].second);
			swap(temp[i], temp[temp[i].second]);
			i--;
		}
	}
	return c;
}
