/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        Node* temp = headRef;
        while(temp){
            if(temp->prev && temp->data == temp->prev->data){
                if(temp->next) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                else temp->prev->next = NULL;
            } 
            temp = temp->next;
        }
        return headRef;
    }
};