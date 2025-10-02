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
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp = head;
        int count =-1;
        while( temp ){
            count++;
            temp = temp->next;
        }
        temp = head;
        int p = 1<<count;
        int ans =0;
        while(temp){
            ans = ans + p*temp->val;
            temp = temp->next;
            p = p/2;
        }
        return ans;
    }
};