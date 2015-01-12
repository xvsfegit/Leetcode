/*************************************************************************
	> File Name: SameTree.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四  1/ 8 22:42:28 2015
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x),left(NULL),right(NULL){}
};
bool isSymmetric(TreeNode* root)
{
    if(root == NULL){
        return true;
    }
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    stack<TreeNode*> p_stack;
    stack<TreeNode*> q_stack;
    while(1){
        if(p == NULL && q == NULL){
            if(p_stack.empty()){
                return true;
            }
            p = p_stack.top();
            q = q_stack.top();
            p_stack.pop();
            q_stack.pop();
            p = p->right;
            q = q->left;
        }
        else if((p && q == NULL) || (p == NULL && q)){
            return false;
        }
        else{
            if(p->val == q->val){
                p_stack.push(p);
                q_stack.push(q);
                p = p->left;
                q = q->right;
            }
            else{
                return false;
            }
        }
    }
    return false;
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    cout << isSymmetric(p) << endl;    
    return 0;
}
