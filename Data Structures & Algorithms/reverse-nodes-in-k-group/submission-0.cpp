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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head; 
        ListNode* groupPrev = dummy;
        
        while (true) {
            ListNode* endGroup = groupPrev;

            for(int i = 0; i < k && endGroup; i++){
                endGroup = endGroup->next;
            }

            if(!endGroup) break;
            ListNode* groupNext = endGroup->next;
            ListNode* prev = groupNext; 
            ListNode* cur = groupPrev->next;

            while(cur != groupNext){
                ListNode* n = cur->next; 
                cur->next = prev;
                prev = cur; 
                cur = n;
            }

            ListNode* first = groupPrev->next; 
            groupPrev->next = endGroup; 
            groupPrev = first; 
        }

        return dummy->next;
    }
};
