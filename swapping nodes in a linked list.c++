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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* s;
        ListNode* slow =head;
        ListNode* fast =head;

        while(k!=1){
            fast = fast->next;
            k--;
            
        }
        s=fast;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        int vals =s->val;
        int vale =slow->val;
       
        s->val = vale;
        slow->val =vals;
        return head;
    }
};
