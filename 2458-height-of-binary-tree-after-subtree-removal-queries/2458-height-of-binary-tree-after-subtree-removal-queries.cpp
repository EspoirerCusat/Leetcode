/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int samay = 0;
        int nMax= 100010;
        void dfs(TreeNode* root,vector<int>& lt, vector<int>& st, vector<int>& ed,int height){
            if(root == nullptr) return ;
            lt[++samay] = height; 
            st[root->val] = samay;
            dfs(root->left,lt,st,ed,height+1);
            dfs(root->right,lt,st,ed,height+1);
            ed[root->val] = samay;
        }
        vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
            vector<int> lt(nMax,0),st(nMax,0),ed(nMax,0);
            vector<int> pre(nMax,0),suf(nMax,0);
            dfs(root,lt,st,ed,0);
            for(int i=1; i<nMax; i++){
                pre[i] = max(pre[i-1],lt[i]);
            }
            for(int i=nMax-2; i>=0; i--){
                suf[i] = max(suf[i+1],lt[i]);
            }
            //for(int i=0; i<10; i++) cout<<pre[i]<<" ";
            vector<int> res;
            for(int x : queries){
                int ans = max(pre[st[x]-1],suf[ed[x]+1]);
                res.push_back(ans);
            }
            return res;
        }
};

















