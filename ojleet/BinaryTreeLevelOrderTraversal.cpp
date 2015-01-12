/*************************************************************************
	> File Name: BinaryTreeLevelOrderTraversal.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  1/12 23:20:45 2015
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector< vector<int> > levelOrder(TreeNode* root)
{
    vector< vector<int> > result;
    if(root == NULL){
        return result;
    }
    stack<TreeNode*> data_stack;
    while(!data_stack.empty()){

    }
    return result;
}



int main(int argc,char* argv[])
{
    return 0;
}
