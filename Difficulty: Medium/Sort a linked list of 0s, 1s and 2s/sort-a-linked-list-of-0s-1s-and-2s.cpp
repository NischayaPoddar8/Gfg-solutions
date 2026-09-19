/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(!head || !head->next) return head;
        Node zeroDummy(0);
        Node oneDummy(0);
        Node twoDummy(0);

        Node* zero = &zeroDummy;
        Node* one = &oneDummy;
        Node* two = &twoDummy;
        
        Node* temp = head;
        
        while(temp){
            Node* next = temp->next;
            temp->next = NULL;
            if(temp->data==0){
                zero->next = temp; // so list ahead of temp is not attatched
                zero = zero->next;
            }
            else if(temp->data==1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }
            temp = next;
        }
        
        zero->next = oneDummy.next;
        if(oneDummy.next) one->next = twoDummy.next;
        else zero->next = twoDummy.next;
        return zeroDummy.next;
    }
};