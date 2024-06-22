Node* removeKthNode(Node* head, int K)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Move the fast pointer K nodes ahead
    while (K > 0 && fast != NULL)
    {
        fast = fast->next;
        K--;
    }

    // If K is greater than the length of the linked list, return the original head
    if (K > 0)
        return head;

    // Move both the slow and fast pointers until the fast pointer reaches the end
    while (fast != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // If the slow pointer is pointing to the head, remove the head
    if (prev == NULL)
        head = head->next;
    else
        prev->next = slow->next;

    // Delete the kth node
    delete slow;

    return head;
}