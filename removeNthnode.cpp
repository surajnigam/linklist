/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

///remove nth node from back side
class Solution {
   
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == nullptr || n <= 0) {
            return head;
        }

        // Step 1: Calculate the length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        // Handle edge case where N is greater than the length of the list
        if (n > length) {
            return head;
        }

        // Step 2: Calculate the position of the node to be removed
        int removeIndex = length - n;

        // Handle case where the node to be removed is the head
        if (removeIndex == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Remove the node
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < removeIndex; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};