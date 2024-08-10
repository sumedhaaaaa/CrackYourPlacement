Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *multiplyLL(Node *head1, Node *head2)
{
    Node* temp = head1;
    long long x = 0;
    while(temp != NULL && temp->data != -1)
    {
        x = x * 10 + temp->data;
        temp = temp->next;
    }

    temp = head2;
    long long y = 0;
    while(temp != NULL && temp->data != -1)
    {
        y = y * 10 + temp->data;
        temp = temp->next;
    }

    long long product = x * y;

    if (product == 0) 
        return new Node(0);
    
    
    Node* head=new Node(-1);
    Node* p=head;

    while(product>0)
    {
        int digit=product%10;
        product=product/10;

        p->next=new Node(digit);
        p=p->next;
    }

    return reverse(head->next);
}
