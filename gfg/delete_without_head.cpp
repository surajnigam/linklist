void deleteNode(Node* del)
{
    // Your code here
    if (del == nullptr || del->next == nullptr) {
        // Cannot delete the last node or a null node
        return;
    }

    Node* temp = del->next;
    del->data = temp->data;
    del->next = temp->next;

    delete temp;
}