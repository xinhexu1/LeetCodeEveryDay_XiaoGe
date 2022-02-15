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
    ListNode* rev(ListNode* r) {
        ListNode* prev = nullptr;
        auto cur = r;
        while (cur) {
            auto temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        ListNode* sentinel;
        auto cur = &sentinel;
        int quo = 0, rem = 0;
        while (l1 && l2) {
            int curSum = l1->val + l2->val + quo;
            quo = curSum / 10;
            rem = curSum % 10;
            *cur = new ListNode(rem);
            cur = &((*cur)->next);
            l1 = l1->next;
            l2 = l2->next;
        }
        auto& rest = (l1)? l1 : l2;
        if (!rest && quo > 0) {
            *cur = new ListNode(quo);
            return rev(sentinel);
        }
        *cur = rest;
        while (rest) {
            int curSum = rest->val + quo;
            quo = curSum / 10;
            rem = curSum % 10;
            rest->val = rem;
            if (!rest->next) break;
            rest = rest->next;
        }
        if (quo > 0) rest->next = new ListNode(quo);
        return rev(sentinel);
    }
};