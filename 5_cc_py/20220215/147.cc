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
    ListNode* findPlace(ListNode* head, int value) {
        ListNode* prev = nullptr;
        auto cur = head;
        while (cur) {
            if (cur->val >= value) return prev;
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        auto cur = head->next;
        auto prev = head;
        while (cur) {
            auto tempNext = cur->next;
            if (cur->val < prev->val) {
                auto p = findPlace(head, cur->val);
                if (!p) {
                    head = new ListNode(cur->val, head);
                } else {
                    ListNode* pNext = p->next;
                    p->next = cur;
                    cur->next = pNext;
                }
                prev->next = tempNext;
            } else {
                prev = cur;
            }
            cur = tempNext;
        }
        return head;
    }
};