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
    
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* Next = nullptr;
        int count = 0;
        while (curr && count < k) {  // safety check added
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        head->next = curr; // connect tail of reversed part to remaining list
        return prev;       //return new head of reversed part
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // count total nodes
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        // dummy node helps to manage the head easily 
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;

        while (count >= k) {
            ListNode* groupStart = curr;
            ListNode* groupEndNext = curr;
            for (int i = 0; i < k; i++) groupEndNext = groupEndNext->next;

            // reverse current k-group 
            ListNode* newGroupHead = reverse(curr, k);
            prevGroupEnd->next = newGroupHead;
            prevGroupEnd = groupStart; // old head becomes end of group
            curr = groupEndNext;
            count -= k;
        }

        prevGroupEnd->next = curr; // connect any remaining nodes
        return dummy.next;         // this is your new head
    }
};
