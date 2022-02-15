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
struct myComp {
    bool operator() (ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        auto tail = &head;
        priority_queue<ListNode*, vector<ListNode*>, myComp> pq;
        for (auto& l : lists) {
            if (l) {
                pq.push(l);
            }
        }
        if (pq.empty()) return nullptr;
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            *tail = new ListNode(cur->val);
            tail = &((*tail)->next);
            pq.pop();
            if (cur->next) {
                pq.push(cur->next);
            }
        }
        return head;
    }
};