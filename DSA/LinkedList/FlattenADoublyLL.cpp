////////////////// Flatten a Multilevel Doubly Linked List ///////////////////

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //Base case: 
        if (head == NULL) {
	        return head;
        }

        Node* curr = head;
        while(curr != NULL){
            // If the current node has a child

	        if(curr->child != NULL){
                //step1: flatten the child nodes
                Node* next = curr->next; // Save the next node
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;
                
                //step2: find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                //step3: attach tail with next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
	        }

            // Move to the next node
	        curr = curr->next;
        }

        return head;
    }
};

//T.C : O[n]
