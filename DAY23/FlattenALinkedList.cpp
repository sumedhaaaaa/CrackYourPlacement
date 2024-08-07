Node* mergeTwoLists(Node* head1, Node* head2) {
    
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node* result;   
    if (head1->data < head2->data) 
    {
        result = head1;
        result->child = mergeTwoLists(head1->child, head2); 
    } else 
    {
        result = head2;   
        result->child = mergeTwoLists(head1, head2->child); 
    }
    return result;
}

Node *flattenLinkedList(Node *head) 
{
    if(!head)
        return head;
    Node* temp = flattenLinkedList(head->next);   
    return mergeTwoLists(head, temp);
}
