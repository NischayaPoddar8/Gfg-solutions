/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
};