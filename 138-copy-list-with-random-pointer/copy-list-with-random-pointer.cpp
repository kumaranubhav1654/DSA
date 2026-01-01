/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node* tmp = head;
        Node* ans = new Node(0);
        Node* tmpNew = ans;

        while(tmp){
            tmpNew->next = new Node(tmp->val);
            mp[tmp] = tmpNew->next;
            tmpNew = tmpNew->next;
            tmp = tmp->next;
        }

        tmpNew = ans->next;
        tmp = head;

        while(tmp){
            if(tmp->random)
            tmpNew->random = mp[tmp->random];
            tmpNew = tmpNew->next;
            tmp = tmp->next;
        }
        return ans->next;
    }
};