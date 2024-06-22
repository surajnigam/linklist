#include <bits/stdc++.h>

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
Node* reverseLinkedList(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    // Reverse the first 'k' nodes of the linked list
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Connect the reversed block with the remaining linked list
    if (next != NULL) {
        head->next = reverseLinkedList(next, k);
    }

    // 'prev' is the new head of the reversed block
    return prev;
}

Node* getListAfterReverseOperation(Node* head, int n, int b[]) {
    Node dummy(0);
    dummy.next = head;
    Node* prevBlock = &dummy;

    int i = 0;
    while (head != NULL && i < n) {
        int blockSize = b[i];

        Node* blockHead = head;
        Node* blockTail = NULL;

        // Traverse 'blockSize' nodes
        for (int j = 0; j < blockSize && head != NULL; j++) {
            blockTail = head;
            head = head->next;
        }

        if (blockTail == NULL) {
            // No more nodes left, exit the loop
            break;
        }

        blockTail->next = NULL;  // Disconnect the block from the remaining list

        // Reverse the block and connect it with the previous block
        prevBlock->next = reverseLinkedList(blockHead, blockSize);
        prevBlock = blockHead;

        i++;
    }

    // Connect the remaining nodes with the list
    prevBlock->next = head;

    return dummy.next;
}





 