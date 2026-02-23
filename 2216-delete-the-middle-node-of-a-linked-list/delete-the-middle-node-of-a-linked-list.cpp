// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;
        
//         if(head->next == NULL) return NULL;
//         while(fast->next->next!=NULL && fast->next->next->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         slow->next= slow->next->next;

//         return head;
//     }
// };


// better way of writting 

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;

        return head;
    }
};