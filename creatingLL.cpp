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


//check circular linklist
bool checklliscircular(node* head)
{
    if(head==NULL)
    return true;

   
    node* temp=head->next;
    while(temp->next!=NULL&&temp->next!=head)
    {
        temp = temp->next;
    }
   
    if(temp==head)
    {
        return true;
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

    display(head);

    cout << "insert for adding at head" << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        int y;
        cin >> y;
        insertathead(head, y);
    }
    display(head);

    if(checklliscircular(head))
    {
        cout<<"circular"<<endl;
    }
    else
    {
        cout<<"not circular"<<endl;
    }

    return 0;
}
