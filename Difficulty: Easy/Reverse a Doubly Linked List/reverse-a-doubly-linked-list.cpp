/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* previous = nullptr;
        
        while(curr){
            Node* next = curr->next;
            curr->prev = next;
            curr->next = previous;
            previous = curr;
            curr = next;
        }
        head = previous;
        return head;
    }
};