
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        
        int duplicate;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->next->val == temp->next->next->val)
            {
                duplicate=temp->next->val;
                
                while(temp->next!=NULL && temp->next->val==duplicate)
                    temp->next=temp->next->next;
            }
            else
                temp=temp->next;
        }
        
        return dummy->next;
    }
};
