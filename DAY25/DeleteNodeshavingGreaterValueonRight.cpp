/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev = NULL;
        ListNode *curr = head, *next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    //just reversing and doing the change will do
    ListNode* removeNodes(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        
        head=reverseList(head);
        
        ListNode* temp=head;
        
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->val > temp->next->val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        return reverseList(head);
    }
};
