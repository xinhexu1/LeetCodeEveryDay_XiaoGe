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
        ListNode* sentinel;
        auto cur = &sentinel;
        while (list1 && list2) {
            auto& l = (list1->val <= list2->val)? list1 : list2;
            *cur = new ListNode(l->val);
            cur = &((*cur)->next);
            l = l->next;
        }
        *cur = (list1)? list1 : list2;
        return sentinel;
    }
};