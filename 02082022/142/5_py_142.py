# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head):
        if not head or not head.next or not head.next.next:
            return None
        fast, slow = head.next.next, head.next
        while fast != slow:
            if not fast.next or not fast.next.next:
                return None
            fast = fast.next.next
            slow = slow.next
        recov = head
        while recov != slow:
            recov = recov.next
            slow = slow.next
        return recov