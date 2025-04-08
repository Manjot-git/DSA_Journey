///////////////////////// Merge 2 Sorted Lists /////////////////////

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        //BASE-CASE
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        //CASE-1
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }else{ //CASE-2
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

//Time Complexity : O( n + m )
