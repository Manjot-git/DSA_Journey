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
    int widthOfBinaryTree(TreeNode* root) { //for CBT
        queue <pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWid = 0;

        while(q.size() > 0){
            int currLevSize = q.size();
            unsigned long long stIdx = q.front().second; //can be 2^31..32.. so need to chnge type //first node index
            unsigned long long  endIdx = q.back().second; //last node index of current level

            maxWid = max(maxWid, (int)(endIdx - stIdx + 1) );

            for(int i=0; i<currLevSize; i++){
                auto currNode = q.front();
                q.pop();

                if(currNode.first->left){
                    q.push({currNode.first->left, currNode.second*2+1});  // left child's CBT index
                }
                if(currNode.first->right){
                    q.push({currNode.first->right, currNode.second*2+2});  // right child's CBT index
                }

            }
        }

        return maxWid;
    }
};
