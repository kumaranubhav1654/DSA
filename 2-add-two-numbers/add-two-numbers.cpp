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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* ansTmp = new ListNode(0);
        ListNode* ans = ansTmp;
        while(l1 && l2){
            sum = l1->val + l2->val;
            ansTmp->next = new ListNode((sum+carry)%10);
            ansTmp=ansTmp->next;
            carry = (sum+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum = l1->val;
            ansTmp->next = new ListNode((sum+carry)%10);
            ansTmp=ansTmp->next;
            carry = (sum+carry)/10;
            l1=l1->next;
        }
        while(l2){
            sum = l2->val;
            ansTmp->next = new ListNode((sum+carry)%10);
            ansTmp=ansTmp->next;
            carry = (sum+carry)/10;
            l2=l2->next;
        }
        if(carry)ansTmp->next = new ListNode(1);
        return ans->next;
    }
};