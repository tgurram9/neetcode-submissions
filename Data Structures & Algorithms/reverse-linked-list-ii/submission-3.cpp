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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(-1);
        dummy.next = head;

        auto it = &dummy;
        ListNode* tmpHead = nullptr;
        ListNode* tmpTail = nullptr;

        int i = 0;
        while (it) {
            if (i == left-1) {
                tmpHead = it;
            }

            if (i == right+1) {
                tmpTail = it;
            }
            i++;
            it = it->next;
        }
        
        auto curr = tmpHead->next;
        auto last = tmpHead->next;
        ListNode* prev = nullptr;
        ListNode* next = curr->next;

        while (curr != tmpTail ) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }

        last->next = tmpTail;
        tmpHead->next = prev;

        return dummy.next;
    }
};