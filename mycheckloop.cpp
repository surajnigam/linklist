#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the tail of a linked list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to create a cyclic linked list
void createCycle(Node*& head, int pos) {
    if (head == nullptr)
        return;

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp != nullptr) {
        tail->next = temp;
    }
}

// Function to check if a linked list has a cycle
Node hasCycle(Node* head) {    //floyed allgo to detect loop in link list
    if (head == nullptr || head->next == nullptr)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}



// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a non-cyclic linked list
    Node* nonCyclicHead = nullptr;
    for (int i = 1; i <= 5; i++) {
        insertAtTail(nonCyclicHead, i);
    }

    cout << "Non-cyclic linked list: ";
    display(nonCyclicHead);
    cout << "Has cycle? " << (hasCycle(nonCyclicHead) ? "Yes" : "No") << endl;

    // Creating a cyclic linked list
    Node* cyclicHead = nullptr;
    for (int i = 1; i <= 5; i++) {
        insertAtTail(cyclicHead, i);
    }

   

    createCycle(cyclicHead, 2);

   
   
    cout << "Has cycle? " << (hasCycle(cyclicHead) ? "Yes" : "No") << endl;
  return 0;
}