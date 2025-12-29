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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* mid = head;
        ListNode* end = head;
        
        while(end && end->next){
            end = end->next->next;
            mid = mid->next;
        }

        ListNode* curr = mid->next;
        mid->next = NULL;

        while(curr){
            ListNode* next = curr->next;
            curr->next = mid;
            mid = curr;
            curr = next;
        }

        curr = head;

        while(mid){
            if(mid->val!=curr->val) return false;
            mid=mid->next;
            curr=curr->next;
        }

        return true;
    }
};