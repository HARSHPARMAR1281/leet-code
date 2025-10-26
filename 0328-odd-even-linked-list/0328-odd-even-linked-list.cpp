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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL||head->next == NULL) return head;
        ListNode * temp = head,  *ptr  =  head;
        ListNode * ist = temp->next;

        int count = 1;
        while(ptr->next != NULL){
            ptr = ptr->next;
            count++;
        }
        int n = count;
        count = count /2;
        while(count-- && n>2){
                temp->next = ist ->next;
                ist->next = NULL;
                ptr->next = ist;
                ptr = ptr->next;
                temp = temp->next;
                ist = temp->next;

            }
        return head;
    }
};