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
bool isSameTree(TreeNode* p,int sum)
{
    stack<TreeNode*> p_stack;
    stack<int> pathSum;
    int curVal = 0;
    while(1){
        if(p == NULL){
            if(p_stack.empty()){
                return false;
            }
            p = p_stack.top();
            p_stack.pop();
            p = p->right;
            curVal = pathSum.top();
            pathSum.pop();
        }
        else{
            curVal += p->val; 
            if(curVal == sum && p->left == NULL && p->right == NULL){
                return true;
            }
            pathSum.push(curVal);
            p_stack.push(p);
            p = p->left;
        }
    }
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    TreeNode* q = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    q->left = new TreeNode(1);
    q->right = new TreeNode(3);
    return 0;
}
