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
    ListNode* ansTmp = new ListNode(0);
    ListNode* ans = ansTmp;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ansTmp->next = new ListNode(l1->val);
                ansTmp = ansTmp->next;
                l1 = l1->next;
            } else {
                ansTmp->next = new ListNode(l2->val);
                ansTmp = ansTmp->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            ansTmp->next = new ListNode(l1->val);
            ansTmp = ansTmp->next;
            l1 = l1->next;
        }
        while (l2) {
            ansTmp->next = new ListNode(l2->val);
            ansTmp = ansTmp->next;
            l2 = l2->next;
        }
        return ans->next;
    }
};