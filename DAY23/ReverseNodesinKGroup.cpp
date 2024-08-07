class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) 
        return NULL; 
    ListNode* current = head; 
    ListNode* next = NULL; 
    ListNode* prev = NULL; 
    int count = 0; 
  
    ListNode* check = head;
        for (int i = 0; i < k; i++) 
        {
            if (!check) return head; 
            check = check->next;
        }
        
    while (current != NULL && count < k) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
  
    
    if (next != NULL) 
        head->next = reverseKGroup(next, k); 
  
   
    return prev; 
} 
    
};
