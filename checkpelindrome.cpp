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

   //reverse a link list
   //reverse the linklist , for this we have to creat three pointers previous , current and next METHOD 1  (ittrative )
       node* reversell(node* &head)     
       {
           node* pre = NULL;
           node* cur=head;
           node* nxt;
           while(cur!=NULL)
           {   nxt= cur->next;
           
               cur->next=pre;
              
               
              pre=cur;
              cur=nxt;
           }
        head=  pre;
           return head;
       }

      

bool isPalindrome(node* head) {
    if (head!=NULL || head->next!=NULL) {
        return true; // Empty list or single node list is considered a palindrome
    }

    // Find the middle node using the slow-fast pointer technique
    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    node* secondHalf = reversell(slow);

    // Compare the first half with the reversed second half
    node* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // It is a palindrome
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
     node* slow = midpoint(head);
      cout<<endl;

     display(slow);
     cout<<endl;

         reversell(slow->next);
         
        display(head);
        // if(ans)
        // cout<<"true"<<endl;
        // else
        // cout<<"false"<<endl;

    return 0;
}
