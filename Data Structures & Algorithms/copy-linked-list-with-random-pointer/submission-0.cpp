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
        unordered_map<Node*,Node*> mp;

        if(head == nullptr) return nullptr;

        Node dummy(0);
        Node* cur_res = &dummy;
        Node* cur = head;

        while(cur != NULL){
            cur_res->next = new Node(cur->val);
            cur_res = cur_res->next;
            mp[cur] = cur_res;
            cur = cur->next;
        }

        cur_res = dummy.next;
        cur = head;
        mp[nullptr] = nullptr;
        while(cur_res != nullptr){
            cur_res->random = mp[cur->random];

            cur_res = cur_res->next;
            cur = cur->next;
        }

        return dummy.next;
    }
};
