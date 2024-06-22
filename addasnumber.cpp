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
//reverse
void reversell(node* &head)     
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
           head=pre;
           return;
       }

//add two link list as a two number
// node* addTwoNumbers(node* l1, node* l2) {
//     node* dummy = new node(0);
//     node* current = dummy;
//     int carry = 0;

//     while (l1 || l2 || carry) {
//         int sum = carry;
//        //if l1 not NULL
//         if (l1) {
//             sum += l1->data;
//             l1 = l1->next;
//         }
//         //if l2 not
//         if (l2) {
//             sum += l2->data;
//             l2 = l2->next;
//         }

//         carry = sum / 10;
//         current->next = new node(sum % 10);
//         current = current->next;
//     }

//     return dummy->next;
// }

node* addTwoNumbers(node* l1, node* l2) {
    node* dummy = new node(0);
    node* current = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        if (sum < 0) {
            sum += 10;
            carry = -1;
        }

        current->next = new node(sum);
        current = current->next;
    }

    return dummy->next;
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

    node *head2 = NULL;
    cout << "insert size of ll2" << endl;
    int m;
    cin >> m;

    cout << "insert for adding at tail" << endl;

    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        insertattail(head2, y);
    }

   display(head);
   display(head2);
  
  cout<<endl;

   reversell(head);
   reversell(head2);

  node* ans= addTwoNumbers(head, head2);

     reversell(ans);

   display(ans);

    return 0;
}
