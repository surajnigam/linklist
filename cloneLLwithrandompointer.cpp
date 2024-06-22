class Solution
{   


    ///form zig zac pattern between two two lLL orginal and clone  prefer love babber

    // step1 : copy linear LL 
    // step2 : mapping directly original and cloned LL
    // step3 : connect random pointer of clone node according to origignal
    // step4 : dis connect two link list 
    // step5 : return clonehead;
    private:
    void insertattail(Node* &clonehead, Node* &clonetail, int data)
    {
        Node* newnode = new Node(data);
        if(clonehead==NULL)
        {
            clonehead=newnode;
            clonetail=newnode;
            
            
        }
        else
        {
        clonetail->next=newnode;
        clonetail=newnode;
        
       
        }
        
    }
    public:
    Node *copyList(Node *head)
    {
        //copy a only first linear LL without random or arb pointer
        Node* temp = head;
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        while(temp!=NULL)
        {  
            insertattail(clonehead,clonetail, temp->data);
            temp=temp->next;
        }
        //connect orginal ll all elements to clone elements direct with same element connect same element in clone LL
        Node* orgcur=head;
        
        Node* clonecur=clonehead;
       
       while(clonecur!=NULL&&orgcur!=NULL)
        {   Node* orgnext=orgcur->next;
           
            orgcur->next=clonecur;
            orgcur=orgnext;
            
             orgnext = clonecur->next;
            clonecur->next=orgcur ;
            clonecur=orgnext;
        }
        
        //assing all random pointer of clone LL similar to org LL
        temp = head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                temp->next->arb= temp->arb?temp->arb->next:temp->arb;
            }
           
            temp=temp->next->next;
        }
        
        //remove connection between org and clone LL
        orgcur=head;
        clonecur=clonehead;
        while(orgcur!=NULL&&clonecur!=NULL)
        {
            orgcur->next=clonecur->next;
            orgcur=orgcur->next;
            if(orgcur!=NULL){
            clonecur->next = orgcur->next;
            }
            clonecur=clonecur->next;
        }
        
        return clonehead;
    }

};