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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        auto head = dummy;

        auto p1 = list1, p2 = list2;

        while (p1 && p2) {
            if (p1->val < p2->val) {
                head->next = p1;
                p1 = p1->next;
            } else {
                head->next = p2;
                p2 = p2->next;
            }
            head = head->next;
        }

        if (p1) {
            head->next = p1;
        }

        if (p2) {
            head->next = p2;
        }

        return dummy->next;
    }
};
