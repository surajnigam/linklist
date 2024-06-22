Node *kReverse(Node *head, int k) {
  int len = 0;
  Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  // For elements which can't be grouped
  if (len < k) {
    return head;
  }
  if (head == NULL) {
    return NULL;
  }
  // step 1: reverse first k nodes
  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;
  int count = 0;
  while (curr != NULL && count < k) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  // step 2: recursion
  if (next != NULL) {
    head->next = kReverse(next, k);
  }
  // step 3: return head
  return prev;
}