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
    ListNode* rotateRight(ListNode* head, int k) {
       ListNode* slow = head;
       ListNode* fast = head;
       ListNode* temp = head;
       if(!head) return nullptr;
       int count =0;
       while(temp){
        temp = temp->next;
        count++;
       }
       if(count>0)k = k%count;

       while(k>0){
        fast = fast->next;
        k--;
       }

       while(fast->next){
        slow = slow ->next;
        fast = fast->next;
       }
       fast->next = head;
       head = slow->next;
       slow->next = nullptr;
       return head;
    }
};