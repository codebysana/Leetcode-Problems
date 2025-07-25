/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
         
        // Step 1: Interleave copied nodes with original nodes
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }

        // Step 2: Assign random pointers to copied nodes
        temp = head;
        while (temp != nullptr) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        
        // Step 3: Separate the original and copied lists
        Node* dummy = new Node(0);
        Node* res = dummy;
        temp = head;

        while(temp != nullptr){
            Node* copyNode = temp->next;
            res->next = copyNode;
            temp->next = copyNode->next;

            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};