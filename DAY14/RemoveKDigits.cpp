class Solution {
public:
   string removeKdigits(std::string num, int k) {
        int n = num.size();
        std::stack<char> st;
        std::vector<char> result;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        // If k is still greater than 0, remove the remaining digits
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }

        if (result.empty()) return "0";
     
        reverse(result.begin(), result.end());
        
       
        return string(result.begin(), result.end());
    }
};
