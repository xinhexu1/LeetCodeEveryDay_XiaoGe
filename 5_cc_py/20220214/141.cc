/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        auto fast = head;
        auto slow = head;
        fast = fast->next;
        while (fast != slow) {
            if (!fast || !fast->next || !fast->next->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};