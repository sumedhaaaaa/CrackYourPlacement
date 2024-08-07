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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        
        ListNode*tempd=new ListNode(-1);
        ListNode* temp=tempd;
        
        while(!pq.empty())
        {
            pair<int,ListNode*>curr=pq.top();
            pq.pop();
            
            if(curr.second->next)
                pq.push({curr.second->next->val,curr.second->next});
            
            temp->next=curr.second;
            temp=temp->next;
              
        }
        return tempd->next;
    }
};
