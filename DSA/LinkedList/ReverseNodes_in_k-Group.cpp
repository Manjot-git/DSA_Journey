////////////////////// Reverse Nodes in k-Group ///////////////////  P--25

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        //Step 1: check if k nodes exist 
        while(cnt < k){
            if(temp == NULL){// If fewer than k nodes remain, return head as is
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        //Step 2: recursively call for rest of LL from the k+1-th node
        ListNode* prevNode = reverseKGroup(temp, k);

        //Step 3: reverse current group
        temp = head; cnt = 0;
        while(cnt < k){
            ListNode* next = temp->next;// Save next node
            temp->next = prevNode;// Reverse the link

            prevNode = temp;// Move prevNode forward
            temp = next;// Move to next node in original list

            cnt++;
        }

        //Step 4: Return the new head of this reversed segment
        return prevNode;
    }
};

//T.C: O[n]
