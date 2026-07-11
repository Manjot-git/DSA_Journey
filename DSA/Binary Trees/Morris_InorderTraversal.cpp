/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        // Case 1: No left child -> Visit & Go Right

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                //finding Inorder Predecessor IP [Rightmost node of left subtree]
                TreeNode* IP = curr->left;

                // Stop if right is NULL OR thread already exists
                while(IP->right != NULL && IP->right != curr){
                    IP = IP->right;
                }

                // Case 2: First time visiting -> Create Thread & Go Left
                if(IP->right == NULL){
                    IP->right = curr;  //create thread
                    curr = curr->left;
                }
                else {  // Case 3: Second time visiting -> Remove Thread, Visit & Go Right
                    IP->right = NULL; // Delete thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;

    }
};

//SC---O[1],    TC-->O[n]

//LOGIC:
// No Left  -> Visit
// IP->right == NULL -> Create Thread
// IP->right == curr -> Remove Thread + Visit
