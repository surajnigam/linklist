/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
     if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;

        while (nextNode != nullptr && nextNode->data == current->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;

            // Remove the duplicate node
            if (duplicate->prev != nullptr) {
                duplicate->prev->next = nextNode;
            }
            if (nextNode != nullptr) {
                nextNode->prev = duplicate->prev;
            }
            delete duplicate;
        }

        current->next = nextNode;
        if (nextNode != nullptr) {
            nextNode->prev = current;
        }

        current = current->next;
    }

    return head;
}
