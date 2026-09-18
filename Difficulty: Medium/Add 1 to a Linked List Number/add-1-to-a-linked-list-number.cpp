/* Structure of linked list Node
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
    Node* addOne(Node* head) {
        // code here
        int pos = -1;
        int idx = 0;
        Node* temp = head;
        while(temp){
            if(temp->data!=9) pos = idx;
            idx++;
            temp = temp->next;
        }
        
        temp = head;
        idx = 0;
        
        // All are -1
        if(pos==-1){
            Node* dummy = new Node(1);
            dummy->next = head;
            temp = head;
            
            while(temp) {
                temp->data = 0;
                temp = temp->next;
            }
            return dummy;    
        }
        
        while(temp){
            if(idx==pos) temp->data+=1;
            else if(idx>pos) temp->data = 0;
            temp = temp->next;
            idx++;
        }
        
        return head;
        
    }
};