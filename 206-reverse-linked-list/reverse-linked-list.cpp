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


 //public: This method is wrong as we are not reversing the link but the values.Also extra space.
//     ListNode* ans = new ListNode(0);
//     ListNode* ans1 = ans;
//     void helper(ListNode* head){
//         if(head == NULL) return;
//         helper(head->next);
//         ans->next = new ListNode(head->val);
//         ans=ans->next;
//     }
//     ListNode* reverseList(ListNode* head) {
//         helper(head);
//         return ans1->next;
//     }
// };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }
};