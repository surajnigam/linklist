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

// insert at head
void insertathead(node *&head, int val)
{   //creating a new node
    node *n = new node(val);
    //connecting new node to head
    n->next = head;
    //moving head pointer to the new node so that other element can connect on head
    head = n;
    return;
}

//deleting key formLL
 void deleteAll(node* &head, int data)
{
    node* curr = head;
    node* prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == data)
        {
            // Node with the desired value found, remove it from the linked list
            if (prev == NULL)
            {
                // If the node to remove is the head node
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            node* temp = curr;
            curr = curr->next;
            delete temp;  // Delete the node
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}


//deleting index node from LL
   void deleteindex(node* &head, int index)
       {   
           
           node* temp=head;
          
           if(index==0){
           head = head->next;
           }
           else{
           temp = head;
            while(index!=1&&temp->next!=NULL)
            {
                temp = temp->next;
               index--;
            }
            node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
           }
            
       }

       //reverse a link list
       void reversell(node* &head)     //reverse the linklist , for this we have to creat three pointers previous , current and next           METHOD 1  (ittrative )
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

int main()
{
   int t;
   cin>>t;
   while(t--){
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

    // cout << "insert for adding at head" << endl;

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     int y;
    //     cin >> y;
    //     insertathead(head, y);
    // }
    // display(head);


    // deleting key from the link list

    cout<<"enter the key which need to delete"<<endl;
    int key;
    cin>>key;
   deleteAll(head,key);
    display(head);


    //deleting index value
    // cout<<"enter the index which need to delete"<<endl;
    // int index;
    // cin>>index;
    // deleteindex(head,index);
    // display(head);


    /*reverse the LL*/
   // reversell( head );
   // display(head);
   }

    return 0;
}
