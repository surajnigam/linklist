void splitCircularList(Node *head)
{
    // Write your code here.
    Node* slow = head;
    Node* fast=head;
    //finding mid
    //step1: made two pointer equal to head slow and fast 
    //step2: when move fast by two step and slow by one step 
    //step3: when fast reaches to end of the LL upto that slow will reach to mid position
    while(fast->next!=head&&fast->next->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* temp=slow->next;
    Node* cur=temp;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    //splinting 
    cur->next = temp;
    slow->next=head;
  Node*  head1=head;
  Node*  head2=temp;

}