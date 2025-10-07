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
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
        
//         ListNode* temp = head;

//         while(temp){
//             ListNode* temp2 = temp;
//             ListNode* min = temp2;
//             while(temp2){
//                 if(temp2->val <= min->val){
//                     min = temp2;
//                 }
//                 temp2 = temp2->next;
//             }
//             swap(min->val, temp->val);
//             temp = temp->next;
//         }
//         return head;
//     }
// };



// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> arr;

//         ListNode* temp = head;

//         while(temp){
//             arr.push_back(temp->val);
//             temp =temp->next;
//         }
//         temp = head;
//         sort(arr.begin(),arr.end());
//         for(int i=0;i<arr.size();i++){

//             temp->val =arr[i];
//             temp = temp->next;
//         }
//         return head;
//     }
// };



class Solution {
public:
    
   ListNode* mergelist(ListNode* left, ListNode* right){
       ListNode* dummy = new ListNode(0);
       ListNode* dummyt = dummy;
       while(left && right){
          if(left->val <= right->val){
            dummyt->next = left;
            left = left->next;
          }
          else{
            dummyt->next = right;
            right = right->next;
          }
          dummyt = dummyt->next;
       }
       if(left) dummyt->next = left;
       else if(right)dummyt->next =right;
       return dummy->next;

   }


    ListNode* getMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            slow = slow->next;
            fast =fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
       
       if(!head || !head->next) return head;

       ListNode* mid = getMid(head);
       ListNode* right = mid->next;
       mid->next = nullptr;

       ListNode* leftlist = sortList(head);
       ListNode* rightlist = sortList(right);

       return mergelist(leftlist,rightlist);
    }
};