/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        
        Node* slow = head;
        Node* fast = head;
        bool cycle = false;
        while(fast && fast->next && !cycle){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                cycle = true;
                fast = head; 
                while(fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        int len = 1;
        Node* startNode = slow;
        slow = slow->next;
        while(slow!=startNode && slow!=NULL){
            len++;
            slow = slow->next;
        }
        if(!cycle) return 0;
        return len;
    }
};