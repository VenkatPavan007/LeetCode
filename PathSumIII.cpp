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
    
    int count = 0;
    void dfs(TreeNode* root, vector<int> &s, int sum)
    {
        if(root == NULL)
            return;        
        
        s.push_back(root->val);        
        
        dfs(root->left, s, sum);        
        
        dfs(root->right, s, sum);        
        
        int n = s.size();
        int localSum= 0 ;
        for(int i=n-1; i>=0; i--)
        {
            localSum+= s[i];
            if(localSum == sum)
                ++count;
        }
        s.pop_back();
        
    }
    
    
    int pathSum(TreeNode* root, int sum) 
    {
        vector<int> s;
        dfs(root, s, sum);
        return count;    
       
    }
};