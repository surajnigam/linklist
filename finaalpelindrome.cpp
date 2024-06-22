ListNode* reverse(ListNode*curr , ListNode*prev){
     if(!curr)return prev;
     ListNode*temp= curr->next;
     curr->next=prev;
     prev=curr;
     return reverse(temp , curr);
 }
    bool isPalindrome(ListNode* head) {
      if(head->next==NULL)return 1;
        ListNode*slow=head,*fast=head;
        ListNode* back=NULL;
        while(fast!=NULL && fast->next!=NULL){
            back=slow;
            slow=slow->next;
            fast=fast->next->next;
            }
           back->next= reverse(back->next , NULL);

        auto x=back->next;
      back->next=NULL;
      while(x && head){
          if(x->val != head->val)return 0;
          x=x->next;
          head=head->next;
      }
       
        return 1;
    }
};