/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    
    
    void getSerial(TreeNode * root, string &data)
    {
        if(root == NULL)
        {
            data+= '*';
            return;
        }
        data += to_string(root->val);
        data += 'a';
        getSerial(root->left, data);
        getSerial(root->right, data);
        
    }
    string serialize(TreeNode* root) 
    {
        string data = "";        
        getSerial(root, data);  
        cout<<data<<endl;
        return data;
    }
    
    // Decodes your encoded data to tree.
    
    TreeNode* getDeserialize(string &data)
    {
        if(data[0] == '*')
        {
            data.erase(data.begin());
            return NULL;
        }        
        int x = 0;
        if(data[0] == '-')
        {
            data.erase(data.begin());            
            while(data[0]!='a')
            {
                x = x*10 + data[0]-'0';
                data.erase(data.begin());
            }
            x = x*-1;
        }
        else
        {   while(data[0]!='a')
            {
                x = x*10 + data[0]-'0';
                data.erase(data.begin());
            }       
        }
        data.erase(data.begin());
        TreeNode *node = new TreeNode(x);        
        node->left = getDeserialize(data);
        node->right = getDeserialize(data);
        return node;
    }
    
    TreeNode* deserialize(string data) 
    { 
        TreeNode *res = getDeserialize(data);        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));