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

// 1, 2, 3

// 1, 2, 3, 4, 5




class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto second = slow->next;
        auto prev = slow->next = nullptr;

        while (second != nullptr) {
            auto tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        auto first = head;
        second = prev;

        // interleave
        while (second) {
            auto fnext = first->next;
            auto snext = second->next;
            first->next = second;
            second->next = fnext;
            first = fnext;
            second = snext;
        }


    }
};
