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
int maxDepth(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    int maxDepth= 0;
    int layer = 0;
    stack<TreeNode*> remainNode;
    remainNode.push(root);
    while(!remainNode.empty()){
    }
    return maxDepth; 
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
