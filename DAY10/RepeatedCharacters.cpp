//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        unordered_map<char, int> mp;

        for(int i=0; i<s.size(); i++) {

            if(mp.find(s[i]) != mp.end()) {

                return s[i];

            } else {

                mp[s[i]] = i;

            }

        }

        return -1;

    }

};

