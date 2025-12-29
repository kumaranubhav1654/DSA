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
        int count = 0;
        ListNode* tmp = head;
        
        while(tmp){
            count++;
            tmp = tmp->next;
        }

        if(count <= 1) return true;

        int tmpCount = count/2;
        if(count%2!=0) tmpCount++;

        tmp = head;

        while(tmpCount--){
            tmp = tmp->next;
        }

        ListNode* tmp2 = tmp->next;
        tmp->next = NULL;

        while(tmp2){
            ListNode* tmp3 = tmp2->next;
            tmp2->next = tmp;
            tmp = tmp2;
            tmp2 = tmp3;
        }

        tmpCount = count/2;
        tmp2 = head;

        while(tmpCount--){
            if(tmp->val!=tmp2->val) return false;
            tmp=tmp->next;
            tmp2=tmp2->next;
        }

        return true;
    }
};