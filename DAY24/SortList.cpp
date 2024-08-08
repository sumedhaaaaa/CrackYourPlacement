class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != nullptr) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != nullptr) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    ListNode* mergeSort(ListNode* head) {
       
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        
        ListNode* mid = findMid(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        
        left = mergeSort(left);
        right = mergeSort(right);

        
        ListNode* result = merge(left, right);

        return result;
    }
};
