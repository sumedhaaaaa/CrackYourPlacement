class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftd= new ListNode(0);
        ListNode* rightd=new ListNode(0);
        
        ListNode* left=leftd;
        ListNode* right=rightd;
        
        while(head!=NULL)
        {
            if(head->val < x)
            {
                left->next=head;
                left=left->next;
            }
            else
            {
                right->next=head;
                right=right->next;
            }
            
            head=head->next;
        }
        
        left->next=rightd->next;
        right->next=NULL;
        
        return leftd->next;
    }
};
