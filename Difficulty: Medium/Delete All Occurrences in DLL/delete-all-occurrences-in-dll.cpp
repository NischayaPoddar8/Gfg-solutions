/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node* temp = head;
        while(temp){
            if(temp->data == x){
                if(temp->prev) temp->prev->next = temp->next;
                else head = head->next;
                if(temp->next) temp->next->prev = temp->prev;
            }
            temp = temp->next;
        }
        return head;
    }
};