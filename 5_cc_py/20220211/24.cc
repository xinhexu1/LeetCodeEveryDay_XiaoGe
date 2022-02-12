using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* sentinel = new ListNode(0, head);
        auto prev = sentinel;
        auto cur = head;
        while (cur) {
            if (!cur->next) break;
            auto curNext = cur->next->next;
            auto nodeNext = cur->next;
            nodeNext->next = cur;
            cur->next = curNext;
            cur = curNext;
            prev->next = nodeNext;
            prev = nodeNext->next;
        }
        return sentinel->next;
    }
};