class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // ✅ base case

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // ✅ to connect later

        // Separate odd and even nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // Connect end of odd list to start of even list ✅
        odd->next = evenHead;

        return head;
    }
};
