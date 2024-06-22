/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/
//deleting first key from the circular link list
node *deleteNode(node *head, int val)
{   if (head == NULL)
        return head;

    node* curr = head;
    node* prev = NULL;

    do {
        if (curr->data == val) {
            if (prev == NULL) { // The first node contains the value
                node* temp = head;

                if (head->next == head) { // Only one node in the list
                    head = NULL;
                } else {
                  while (curr->next != head) { //if more them one node then reaching head pointer
                    curr = curr->next; 
                  }

                    curr->next = head->next; //connecting last node at the node next of head
                    head = head->next; //moving head forward
                }

                delete temp;
                return head;
            } else {
                prev->next = curr->next;
                delete curr;
                return head;
            }
        }

        prev = curr;
        curr = curr->next;
    } while (curr != head);

    // Key not found, return the same list
    return head;
}
//deleting all node from circular link list which are matched with the key
void deleteAll(Node* &head, int key)
{
    if (head == nullptr) {
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    do {
        if (curr->data == key) {
            // Node with the desired value found, remove it from the linked list
            if (prev == nullptr) {
                // If the node to remove is the head node
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }

                if (head == head->next) {
                    delete head;
                    head = nullptr;
                    return;
                }

                last->next = head->next;
                Node* temp = head;
                head = head->next;
                delete temp;
                curr = head;
            } else {
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != head);
}

Node* deleteNode(Node* head, int key) 
{
    // Write your code here.
    deleteAll(head,key);
   return head;     
}