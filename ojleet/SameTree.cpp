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
bool isSameTree(TreeNode* p,TreeNode* q)
{
    if(p == NULL && q == NULL){
        return true;
    }
    stack<TreeNode*> p_stack;
    stack<TreeNode*> q_stack;
    while(1){
        if(p && q == NULL){
            return false;
        }
        else if(p == NULL && q){
            return false;
        }
        else{
            if(p->val == q->val){
                p_stack.push(p);
                q_stack.push(q);
                p = p->left;
                q = q->left;
            }
            if(p == NULL && q == NULL){
                p = p_stack.top();
                p_stack.pop();
                q = q_stack.top();
                q_stack.pop();
            }
        }
    }
    return false;
}

int main(int argc,char* argv[])
{
    return 0;
}
