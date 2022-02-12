// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentinel = new ListNode(0, head);
        auto last = sentinel;
        auto cur = head;
        while (cur) {
            // silly way, go along the ListNode to see if it can afford k nodes, o/w break
            int trial = 0;
            ListNode* t = cur;
            while (t && trial < k) {
                t = t->next;
                ++trial;
            }
            if (trial < k) break;
            
            // reverse linkedList, normal way
            ListNode* prev = nullptr;
            int counter = 0;
            ListNode* curLast = cur;
            while (counter < k) {
                auto nextCur = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nextCur;
                ++counter;
            }
            // connect the reversed linkedList with last node, reset last node
            last->next = prev;
            last = curLast;
        }
        last->next = cur;
        return sentinel->next;
    }
};