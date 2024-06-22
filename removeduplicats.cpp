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


//remove duplicate in unshorted link list by map (O(N))
void removeDuplicates(node* &head) {
    if (head == NULL)
        return;

    unordered_set<int> seen;
    node* curr = head;
    node* prev = NULL;

    while (curr != NULL) {
        // If current element is already seen, remove it from the list
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}
   
//remove duplicate in unshorted link list (Nlog(N))
void removeDuplicatesusingloop(node* &head) {
    if (head == NULL)
        return;

    node* current = head;

    while (current != NULL) {
        node* runner = current;
        
        // Compare current node with all subsequent nodes
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Duplicate found, remove the node
                node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}
//remove duplicat for shorted link list
void removeduplicate(node* &head)
{ 
    node* cur=head;
    node* nxt;
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        return;
    }
    while(cur!=NULL&&cur->next!=NULL)
    {
      nxt=cur->next;
      if(cur->data==nxt->data)
      {
        node* todelete = nxt;
        cur->next = cur->next->next;
        delete todelete;
      }
      else
      {
        cur=cur->next;
      }
     
    }
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

   // removeduplicate(head);
   //removeDuplicates(head);
removeDuplicates(head);

    display(head);

   

    return 0;
}
