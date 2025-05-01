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
        int carry =0;
        ListNode* sum = new ListNode(0);
        ListNode* t =sum;
        
        while(l1!=NULL || l2!=NULL){
               int s;
            if(l1!=NULL && l2!=NULL){
                s= l1->val+l2->val+carry;
                carry = s/10;
                s = s%10;
                ListNode* dummy = new ListNode(s);
                t->next = dummy;
                t= t->next;
                l1 = l1->next;
                l2 = l2->next;
            }

            else if(l1!=NULL && l2 == NULL){
                s = l1->val + carry;
                carry = s/10;
                s = s%10;
                ListNode* dummy = new ListNode(s);
                t->next = dummy;
                t= t->next;
                l1 = l1->next;

            }

            else if(l2!=NULL && l1 == NULL){
                s = l2->val + carry;
                carry = s/10;
                s = s%10;
                ListNode* dummy = new ListNode(s);
                t->next = dummy;
                t= t->next;
                l2 = l2->next;
            }
        }

        if(carry == 1){
             ListNode* dummy = new ListNode(carry);
                t->next = dummy;
                t= t->next;
        }

        return sum->next;
    }
};
