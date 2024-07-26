//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
         unordered_map<string, vector<string>> mp;

        for(int i = 0; i < string_list.size(); i++) {
            string word = string_list[i];
            string sorted_word = word; 
            sort(sorted_word.begin(), sorted_word.end());
            mp[sorted_word].push_back(word);
        }

        vector<vector<string>> res;
        for(auto it = mp.begin(); it != mp.end(); it++)
            res.push_back(it->second);
        
      
        

        return res;
    }
};

//{ Driver Code Starts.

