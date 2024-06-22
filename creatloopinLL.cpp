#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a node at the tail of a linked list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to create a cyclic linked list
void createCycle(Node*& head, int pos) {
    if (head == NULL)
        return;

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        tail->next = temp;
    }
}

// Function to check if a linked list has a cycle
 //floyed allgo to detect loop in link list
bool hasCycle(Node* head)
    {   
    if (head == NULL || head->next == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
    }

 //detecting node at which loop start
 Node* hasnode(Node* head)
  {   
    if (head == NULL || head->next == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return fast;
    }
    return NULL;
  }

    //give index number from where loop start also give vale of the index 
Node* findnode(Node* head)
{    
    if(hasCycle(head))
    {
      Node* fast = hasnode(head);
      Node* slow = head;
     
      while(slow!=fast)
      {
            slow=slow->next;
            fast=fast->next;
            
      }
       cout<<slow->data<<endl;
      return slow;
    }
    else 
    return NULL;

}

//methode 2nd to detect loop
//detecting loop methode 2
bool detectcycle(Node* head)
{
     if(head==NULL)
     {
        return false;
     }
    Node* temp=head;
    map< Node*, bool> visited;
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

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a non-cyclic linked list
    Node* nonCyclicHead = NULL;
    for (int i = 1; i <= 5; i++) {
        insertAtTail(nonCyclicHead, i);
    }

    
    // Creating a cyclic linked list
    Node* cyclicHead = NULL;
    for (int i = 1; i <= 5; i++) {
        insertAtTail(cyclicHead, i);
    }

   cout<< findnode( cyclicHead)<<endl;
    
  return 0;
}