/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, int> mp;

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while( tempA !=NULL || tempB != NULL){
            if(tempA)mp[tempA]++;
            if(tempB)mp[tempB]++;

            if(mp[tempA] > 1) return tempA;
            if(mp[tempB] > 1) return tempB;
            if(tempA)tempA = tempA->next;
            if(tempB)tempB = tempB->next;
        }
        return 0;
    }
};