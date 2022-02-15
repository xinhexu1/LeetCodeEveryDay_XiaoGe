/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nmap;
        Node* sentinel;
        if (!head) return head;
        auto cur = &sentinel;
        auto refNode = head;
        while (refNode) {
            *cur = new Node(refNode->val);
            nmap[refNode] = *cur;
            cur = &((*cur)->next);
            refNode = refNode->next;
        }
        auto curr = &sentinel;
        refNode = head;
        while (refNode) {
            (*curr)->random = nmap[refNode->random];
            curr = &((*curr)->next);
            refNode = refNode->next;
        }
        return sentinel;
    }
};