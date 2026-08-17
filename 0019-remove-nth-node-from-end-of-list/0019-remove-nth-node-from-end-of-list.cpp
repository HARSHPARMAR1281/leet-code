class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* ptr = head;
        while (ptr) {
            count++;
            ptr = ptr->next;
        }
        if (count == n) {
            return head->next;
        }
        ptr = head;

        for (int i = 1; i < count - n; i++) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};