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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* headTmp = head;

        while(headTmp){
            headTmp=headTmp->next;
            count++;
        }

        if(n==count) return head->next;

        headTmp = head;
        ListNode* prev = NULL;

        count -=n;

        while(count--){
            prev = headTmp;
            headTmp = headTmp->next;
        }
        
        prev->next = headTmp->next;
        return head;
    }
};