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



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp =temp->next;
        }
        temp = head;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){

            temp->val =arr[i];
            temp = temp->next;
        }
        return head;
    }
};