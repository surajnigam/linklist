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

//reverse ll iin k groups
node *kReverse(node *head, int k) {
  int len = 0;
  node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  // For elements which can't be grouped
  if (len < k) {
    return head;
  }
  if (head == NULL) {
    return NULL;
  }
  // step 1: reverse first k nodes
  node *prev = NULL;
  node *curr = head;
  node *next = NULL;
  int count = 0;


  while (curr != NULL && count < k) {//reversing  first k nodes
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  // step 2: recursion
  if (next != NULL) {
    head->next = kReverse(next, k);//connecting reverse sub list with the remaining unrevese list
  }
  // step 3: return head
  return prev;
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
//  int t;
//  cout<<"enter the size of array"<<endl;
//  cin>>t;
//  int arr[t];
//  for(int i=0; i<t; i++)
//  {
//     int y ;
//     cin>>y;
//     arr[i]=y;
//  }
  int k;
  cout<<"enter k for reverse in in k-groups"<<endl;
  cin>>k;
  head = kReverse(head,k); 
    display(head);

    return 0;
}
