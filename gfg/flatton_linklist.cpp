// Node *flatten(Node *root)
// {
//    if(!root->next){
//    return root;}
   
//    root->next=flatten(root->next);
   
//    Node *bott=root->bottom;  
//    Node *nxt=root->next;
//    Node *temp=root;
   
//    root->next=NULL;  //to break remaining list from the root
   
//    while(nxt){
//         if((!bott)||bott->data>nxt->data){
//             temp->bottom=nxt;
//             temp=nxt;
//             nxt=nxt->bottom;
//             temp->bottom=bott;
//         }else{
//             bott=bott->bottom;
//             temp=temp->bottom;
//         }
//    }temp->bottom=bott;
//    return root;
// }


Node* merge(Node*root, Node*nxt){
    if(root==NULL) return nxt;
    if(nxt==NULL) return root;
    
    Node* ans = NULL;
    if(root->data < nxt->data){
        ans = root;
        root->bottom = merge(root->bottom, nxt);
    }else{
        ans = nxt;
        nxt->bottom = merge(root, nxt->bottom);
    }
    return ans;
}

Node *flatten(Node *root) {
    if(root==NULL)
    return NULL;
    
    Node* mergeLList = merge(root, flatten(root->next));
    return mergeLList;
}
