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

//merge two shorted linklist
// step1: first we select which should we first or which should we second link list
//        whose first node data is greateer consider it second LL 
// step2: select first node of 2nd LL and compare its data with cur1 and next1 data of LL1 
// step3: if it can fit in between then add there and update the pointer_safety
// step4: other wise update pointer also check the cur1->next is NULL or not 
// step 5: if next1 is NULL then add connect cur to cur2

node* mergeshort(node* &head,node* &head2)
{  //if first one node has only one node 
    if(head!=NULL&&head->next==NULL)
    {
        head->next=head2;
        return head;
    }
    
      if(head==NULL)
    return head2;
    if(head2==NULL)
    return head;

    node* cur1 = head;
    node* next1 = cur1->next;
    node* cur2 = head2;
    node* next2=cur2->next;
// if head has only one node the next1 == null 
//then first head not move inside the loop so it will return att starting if condition
   while(cur2!=NULL&&next1!=NULL)
   {
    if((cur2->data>=cur1->data)&&(cur2->data<=next1->data))
    {
       //adding in between cur1 and next1
       cur1->next = cur2;
       next2= cur2->next;
       cur2->next = next1;

       //updating pointer after adding
       cur1=cur2;
       cur2=next2;
    }
    else
    {  
        // updating pointer 
        cur1=cur1->next;
        next1=next1->next;
        // checking next1 reach to NULL
        if(next1==NULL)
        {
            cur1->next = cur2;
             return head;
        }
   
   }
   }
    return head;
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
 node* ans;
   if(head->data<head2->data)
   ans=mergeshort(head,head2);
   else
   ans = mergeshort(head2,head);

   display(ans);

   

    return 0;
}
