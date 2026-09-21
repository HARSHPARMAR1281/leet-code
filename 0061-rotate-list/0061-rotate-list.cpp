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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int n = 1;
        ListNode* ptr = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
            n++;
        }

        k = k % n;

        if (k == 0) return head;
        ptr->next = head;
        int left = n - k;
        ListNode* right = head;
        for (int i = 1; i < left; i++) {
            right = right->next;
        }
        head = right->next;
        right->next = NULL;

        return head;
    }
};