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
    ListNode* swapPairs(ListNode* head) {
        //BaseCase: if list is empty or has only one node, no swap needed
        if(head == NULL || head->next == NULL) return head;

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;// Save the next pair's first node
            
            // Swap first and second nodes
            sec->next = first;
            first->next = third;
            
             // Link previous pair's last node to current swapped pair
            if(prev != NULL){
                prev->next = sec;
            }else{
                head = sec;// Update head during the 1st swap
            }

            // Prepare for next swap
            prev = first;
            first = third;
            
            // Check if there's a next pair to swap
            if(third != NULL){
                sec = third->next;
            }else{
                sec = NULL;
            }
        }

        return head;
    }
};

//Time Complexity:
//      O(n) — each node is visited once.
