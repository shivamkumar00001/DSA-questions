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
    ListNode* deleteDuplicates(ListNode* head) {
           
           if(!head) return head;
           ListNode* temp = head;
           ListNode* prev = head;

           while(temp){
              if(temp->val == prev->val){
                temp = temp->next;
                continue;
              }
              else{
                prev->next = temp;
                // temp->prev = prev;
                prev = prev->next;
              }
           }
           prev->next = nullptr;
           return head;
    }
};