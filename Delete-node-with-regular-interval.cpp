/**
 * Definition of linked list
 * class ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int val = 0) {
 *         this -> val = val;
 *     }
 *     ListNode(int val, ListNode* next) {
 *         this -> val = val;
 *         this -> next = next;
 *     }
 * }
 */

 //we need include a element and remove b nodes from LL repidaly until it cur == null
ListNode* deleteNodesOnRegularInterval(int a, int b, ListNode* head) {
    ListNode* curr = head; 
    while(curr != nullptr)
    {
        // first traverse a nodes
        int k = a;
        ListNode* prev = nullptr;
        while(curr != nullptr && k--) //including a nodes
        {
            prev= curr;
            curr=curr->next;
        }
        int r = b;
        ListNode* present = curr;
        ListNode* td = prev;
 
        //delete b nodes

        while(curr != nullptr && r--)//deleting b nodes 
        {
            td->next = curr->next;
            delete curr;
            curr = td->next;
        }
         if(curr == nullptr)
        {
            break;
        }
    } 
    return head;
}