void merge(Node* head1, Node* head2)

{

    //    Write your code here
    //add elements of second node at alter nate position of first link list

 

    while(head1 != NULL){

        Node* store = head2->next;

        head2->next = head1->next;

        head1->next = head2;

 

        head1 = head1->next->next;

        head2 = store;

    }

 

}