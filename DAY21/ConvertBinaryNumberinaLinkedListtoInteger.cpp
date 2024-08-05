class Solution {
public:
   int getDecimalValue(ListNode* head) {
    ListNode* temp = head;
    vector<int> res;
    while(temp!= NULL) {
        res.push_back(temp->val); 
        temp = temp->next;
    }
    
    int sum = 0;
    int power = 0; 
    
    for(int i = res.size() - 1; i >= 0; i--) {
        sum += res[i] * pow(2, power); 
        power++; 
    }
    
    return sum;
}
};
