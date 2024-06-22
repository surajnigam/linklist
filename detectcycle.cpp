#include <bits/stdc++.h>
#include<map>
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

 void makecycle(node* head)
 {
    node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next = head->next;
    return;
 }
 
//  check weather the link list is circular or not
bool isCircular(node* head){
   if(head==NULL)
   return true;
   node* temp=head->next;
   while(temp!=NULL&&temp->data!=-1)
   {
       if(temp==head) return true;
       temp->data = -1;
       temp=temp->next;
   }
   return false;
}
//detect cycle
bool detectcycle(node* head)
{
     if(head==NULL)
     {
        return false;
     }
    node* temp=head;
    map< node*, bool> visited;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
       {
       // cout<<"cycle detected"<<endl;
        return true;
       }
        visited[temp]=true;
       temp=temp->next;
      
    
    }
    return false;
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

    
    
//   if( detectcycle(head))
//   cout<<"cycle detected"<<endl;
//   else
//   cout<<"cycle not detected"<<endl;

  
  


   if( detectcycle(head))
  cout<<"cycle detected"<<endl;
  else
  cout<<"cycle not detected"<<endl;

    // display(head);

   
    return 0;
}
