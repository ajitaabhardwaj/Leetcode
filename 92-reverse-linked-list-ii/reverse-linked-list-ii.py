# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        count = 1
        curr = head
        oldprev = ListNode(0)
        oldprev.next = head
        if left == right:
            return head

        while count < left:
            oldprev = curr
            curr = curr.next
            count+=1

        firstrev = curr
        prev = oldprev
        while count <= right:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
            count+=1

        
        firstrev.next = curr
        oldprev.next = prev

        if left == 1:
            return oldprev.next
        return head
        
        


        