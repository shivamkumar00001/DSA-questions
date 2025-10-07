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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp =l1;
        ListNode* temp2 =l2;
        int carry =0;
        ListNode* dummy = new ListNode(0);
        ListNode* dummyt = dummy;
        while(temp && temp2){
           int sum =0;
            sum = temp->val + temp2->val +carry;
            carry = sum/10;
            int val = sum%10;
            dummyt->next = new ListNode(val);
            dummyt = dummyt->next;
            temp =temp ->next;
            temp2 = temp2->next;
        }
        while(temp){
            int sum = temp->val +carry;
            carry = sum/10;
            int val = sum%10;
            dummyt->next = new ListNode(val);
            dummyt = dummyt->next;
            temp =temp->next;
        }
        while(temp2){
            int sum = temp2->val +carry;
            carry =sum /10;
            int val =sum%10;
            dummyt->next= new ListNode(val);
            dummyt = dummyt->next;
            temp2 =temp2->next;
        }
        if(carry>0) dummyt->next = new ListNode(carry);
        return dummy ->next;
    }
};