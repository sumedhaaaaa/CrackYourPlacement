class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){ 
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head){
           next=head->next;
           head->next=prev;
           prev=head;
           head=next; 
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
         ListNode* mid=middleNode(head);
        ListNode* head2=mid->next;
        
        mid->next=NULL;
        
        head2=reverseList(head2);
        
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
       while(head!=NULL && head2!=NULL)
       {
           temp->next=head;
           head=head->next;
           
           temp=temp->next;
           
           temp->next=head2;
           head2=head2->next;
           
           temp=temp->next;
       }
        if(head!=NULL)
        {
            temp->next=head;
            head=head->next;
            temp=temp->next;
        }
        
        if(head2!=NULL)
        {
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
        
        
    }
};
