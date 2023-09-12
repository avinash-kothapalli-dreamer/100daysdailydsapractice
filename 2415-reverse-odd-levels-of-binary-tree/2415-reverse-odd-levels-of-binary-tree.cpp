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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        vector<int>values;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            int i=0;
            while(i<size){
                TreeNode* node = q.front();
                q.pop();
               // int i=0;
                if(level%2){
                    node->val = values[size-1-i];
                    
                }
                i++;
                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            
            level++;
            values=temp;
        }
        return root;
    }
};