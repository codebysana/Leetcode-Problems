/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* isReverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* node = isReverse(slow);

      while(node != NULL){
        if(head->val != node->val){
            return false;
        }
        head = head->next;
        node = node->next;
      }
      return true;
    } 
};