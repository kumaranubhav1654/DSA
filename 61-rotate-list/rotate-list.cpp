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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head;

        int len = 0;
        ListNode* headTmp = head;
        ListNode* lastheadTmp = headTmp;

        while(headTmp){
            lastheadTmp = headTmp;
            headTmp = headTmp->next;
            len++;
        }

        if(!(k%len)) return head;

        k = len - (k%len);
        headTmp = head;
        ListNode* prevheadTmp = head;

        while(k--){
            prevheadTmp = headTmp;
            headTmp = headTmp->next;
        }

        prevheadTmp->next = NULL;
        lastheadTmp->next=head;

        return headTmp;
    }
};