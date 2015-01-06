/*************************************************************************
	> File Name: SameTree.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四  1/ 8 22:42:28 2015
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x),left(NULL),right(NULL){}
};
/*
 */
int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int maxDepth = 0;
    int minDepth = (unsigned int)(-1);
    queue<TreeNode*> remainNodeQ;
    remainNodeQ.push(root);
    while(!remainNodeQ.empty()){
        int remianLen = remainNodeQ.size();
        ++maxDepth;
        while(remianLen--){
            TreeNode* curNode = remainNodeQ.front();
            remainNodeQ.pop();
            if(curNode->left == NULL && curNode->right == NULL){
                if(maxDepth < minDepth){
                    minDepth = maxDepth;
                }
            } 
            if(curNode->left){
                remainNodeQ.push(curNode->left);
            }
            if(curNode->right){
                remainNodeQ.push(curNode->right);
            }
        }
    }
    return minDepth; 
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    //p->right->left = new TreeNode(5);
    //p->right->left->right = new TreeNode(5);
    p->left->right = new TreeNode(6);
    //p->right->right->right = new TreeNode(6);
    p->left->left = new TreeNode(3);
    //p->left->left->left = new TreeNode(4);
    cout << maxDepth(p) << endl;
    return 0;
}
