Node* reverseList(Node* head) {
        Node* prev = NULL;

        while (head) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
    int getLength(Node* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        Node* l1 = reverseList(head1);
        Node* l2 = reverseList(head2);
        
        Node* res = NULL;
        int borrow = 0;
        
        while (l1 != NULL && l2 != NULL) {
            int val1 = l1->data;
            int val2 = l2->data;
            
            int diff = val1 - val2 - borrow;
            borrow = 0;
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            
            Node* newNode = new Node(diff);
            newNode->next = res;
            res = newNode;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) {
            int val1 = l1->data;
            int diff = val1 - borrow;
            borrow = 0;
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            
            Node* newNode = new Node(diff);
            newNode->next = res;
            res = newNode;
            
            l1 = l1->next;
        }
        
        return reverseList(res); // Reverse the result to correct the order
    }
};
