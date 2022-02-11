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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* fast = sentinel;
        ListNode* slow = head;
        ListNode* last = head;
        while (true) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                last = slow;
                slow = slow->next;
            }
            else {
                break;
            }
        }
        last->next = nullptr;
        
        ListNode* cur = slow;
        ListNode* prev = nullptr;
        while (cur) {
            auto temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        auto curr = head;
        while (curr) {
            auto tempCurr = curr->next;
            curr->next = prev;
            auto tempPrev = prev->next;
            if (tempCurr) prev->next = tempCurr;
            curr = tempCurr;
            prev = tempPrev;
        }
    }
};