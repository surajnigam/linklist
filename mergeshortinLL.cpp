#include <bits/stdc++.h>
using namespace std; 

// insert at head 1) insert at tail, 2) delete key , 3) delete index number
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// inster at tail side
void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    //creat a pointer initial set at head
    //move the temp pointer to end of LL 

    node *temp = head;
    while (temp->next != NULL)
    {  //reaching at the end
        temp = temp->next;
    }
    //adding at the end of LL
    temp->next = n;
    return;
}

 //finding mid
 node* findmid(node* &head)
    {    if (head == NULL || head->next == NULL) {
        return head;
    }
        node* slow=head;
        node* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
//mersge short in linklist
node* mergeshort(node* &first, node* &second)
    {  
        if(first==NULL)
        return second;
        if(second==NULL)
        return first;

        node* ans = new node(-1);
        node* temp = ans;
        while(first!=NULL&&second!=NULL)
        {
            if(first->data > second->data)
            {
               temp->next = second;
                temp=second;
               second=second->next;
           }
           else
           {
               temp->next = first;
               temp = first;
               first = first->next;
           }

        }
        while(first!=NULL)
        {
             temp->next = first;
              temp = first;
               first = first->next;
        }
        while(second!=NULL)
        {
            temp->next = second;
             
            temp=second;
                second=second->next;
        }

      return ans->next;
    }
//shorting and merging
    node* sortList(node* head) {
      
        if(head==NULL||head->next==NULL){
            return head;}

       node* mid = findmid(head);
        node* first = head;         
        node* second = mid->next;
        mid->next=NULL;

        first = sortList(first);
        second = sortList(second);
        node* ans = mergeshort(first, second);

        
        return ans;
    }
// display linklist
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

int main()
{

    node *head = NULL;
    cout << "insert size of ll" << endl;
    int n;
    cin >> n;

    cout << "insert for adding at tail" << endl;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertattail(head, x);
    }

    display(head);

   node* ans = sortList(head);

    display(ans);

    return 0;
}
