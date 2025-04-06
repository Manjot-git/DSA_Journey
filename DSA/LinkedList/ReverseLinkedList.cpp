////////////////////////// REVERSE A LINKED LIST {problem no. 206}///////////////////////

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;   // Save next node
            curr->next = prev;   // Reverse the link

            prev = curr; // Move prev to current
            curr = next; // Move to next node
        }
        return prev;
    }
};

/*((Notes))----> prev: Keeps track of the previous node (starts as NULL because the new tail will point to NULL).

curr: Current node being processed.

next: Temporarily stores the next node (to avoid losing the rest of the list during reversal).*/
