
Node* sortList(Node *head){
    // Write your code here.
    Node* zeroD=new Node(0);
    Node* oneD=new Node(0);
    Node* twoD=new Node(0);

    Node* zero=zeroD;
    Node* one=oneD;
    Node* two=twoD;

    Node* curr=head;
    while(curr)
    {
        if(curr->data == 0)
        {
            zero->next=curr;
            zero=zero->next;
        }
        else if(curr->data == 1)
        {
            one->next=curr;
            one=one->next;
        }
        else {
            two->next=curr;
            two=two->next;
        }
        curr=curr->next;
    }

    zero->next = NULL;
    one->next = NULL;
    two->next = NULL;

    zero->next = oneD->next;
    one->next = twoD->next;

    return zeroD->next;
}
