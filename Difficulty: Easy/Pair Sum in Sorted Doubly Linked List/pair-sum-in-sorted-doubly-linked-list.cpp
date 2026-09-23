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
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        Node* back = head;
        while(back->next){
            back = back->next;
        }
        Node* front = head;
        vector<vector<int>>ans;
        while(front!=back && back->next!=front){
            
            if(front->data + back->data == target){
                ans.push_back({front->data,back->data});
                front = front->next;
                back = back->prev;
            }
            else if(front->data + back->data > target) back = back->prev;
            else front = front->next;
        }
        
        return ans;
    }
};