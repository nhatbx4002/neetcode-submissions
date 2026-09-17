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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode dummy(0);
        ListNode* cur_res = &dummy;

        while(cur1 != nullptr && cur2 != nullptr){
            int val1 = (cur1 != nullptr) ? cur1->val : 0;
            int val2 = (cur2 != nullptr) ? cur2->val : 0;

            if(val1 <= val2){
                cur_res->next = cur1;
                cur1 = cur1->next;
            }else{
                cur_res->next = cur2;
                cur2 = cur2->next;
            }
            cur_res = cur_res->next;
        }
        cur_res->next = (cur1 != nullptr) ? cur1 : cur2;

        return dummy.next;
    }
};