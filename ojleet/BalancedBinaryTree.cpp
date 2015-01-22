/*************************************************************************
	> File Name: SameTree.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四  1/ 8 22:42:28 2015
 ************************************************************************/

#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x),left(NULL),right(NULL){}
};
/*
 */
int treeHight(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    int left = treeHight(root->left) + 1;
    int right = treeHight(root->right) + 1;
    return right > left ? right : left;
}
bool isBalanced(TreeNode* root)
{
    if(root == NULL)
        return true;
    bool leftResult = isBalanced(root->left);
    bool rightResult = isBalanced(root->right);
    int leftHight = treeHight(root->left);
    int rightHight = treeHight(root->right);
    bool comResult = abs(leftHight - rightHight) <= 1;
    return leftResult && rightResult && comResult; 
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    //p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    //p->right->left = new TreeNode(5);
    //p->right->left->right = new TreeNode(5);
    p->right->right = new TreeNode(6);
    //p->right->right->right = new TreeNode(6);
    //p->left->left = new TreeNode(3);
    //p->left->left->left = new TreeNode(4);
    cout << treeHight(p) << endl;
    cout << isBalanced(p) << endl;
    return 0;
}
