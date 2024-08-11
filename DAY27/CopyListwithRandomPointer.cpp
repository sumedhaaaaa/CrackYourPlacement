class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* prev=NULL;
        Node* curr=head;
        Node* newhead=NULL;
        
        if(!head)
            return NULL;
        map<Node*, Node*> mp;
        
        while(curr)
        {
            Node* temp=new Node(curr->val);
            mp[curr]=temp;
            if(newhead==NULL)
            {
                newhead=temp;
                prev=newhead;
            }
           else
           { 
                prev->next=temp;
                prev=temp;
           }
            curr=curr->next;
            
        }
        
        curr=head;
        Node* newcurr=newhead;
        
        while(curr)
        {
            if(curr->random==NULL)
            {
                newcurr->random==NULL;
            }
            else
            {
                newcurr->random=mp[curr->random];
            }
            
            newcurr=newcurr->next;
            curr=curr->next;
        }
        return newhead;
    }
};
