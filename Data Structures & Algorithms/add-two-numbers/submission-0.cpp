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
        
        ListNode dummy(0);
        ListNode* so1 = l1; 
        ListNode* so2 = l2;
        ListNode* cur_res = &dummy;
        int nho = 0;

        while(so1 != nullptr || so2 != nullptr || nho != 0){

            int val1 = (so1 != nullptr)? so1->val : 0;
            int val2 = (so2 != nullptr)? so2->val : 0;
            int sum = val1 + val2 + nho;

            cur_res->next = new ListNode(sum%10);
            
            nho = sum/10;

            if(so1 != nullptr) so1 = so1->next;
            if(so2 != nullptr) so2 = so2->next;
            cur_res = cur_res->next;
        }

        return dummy.next;
    }
};
