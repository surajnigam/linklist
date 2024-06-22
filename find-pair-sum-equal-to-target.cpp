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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    if (head == NULL) {
        return vector<pair<int, int>>(); // Return an empty vector for the edge case where the list is empty.
    }
    
    Node* strt = head;
    Node* end = head;
   
    while (end->next != NULL)
    {
        end = end->next;             
    }
    
    vector<pair<int,int>> ans;
    while (strt < end) // Add the condition strt->next != end
    {
        int sum = strt->data + end->data;
        if (sum == k)
        {
            pair<int,int> p = make_pair(strt->data, end->data);
            ans.push_back(p);
            strt = strt->next;
            end = end->prev;
           
        }
        else if (sum > k)
        {
            end = end->prev;
           
        }
        else
        {
            strt = strt->next;
           
        }
    }
    return ans;
} 


