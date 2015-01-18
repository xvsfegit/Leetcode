/*************************************************************************
	> File Name: BinaryTreeLevelOrderTraversal.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 一  1/12 23:20:45 2015
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
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
    typedef queue<TreeNode*> treeNodeStack;
    treeNodeStack* current = new treeNodeStack;
    treeNodeStack* next = new treeNodeStack;
    (*next).push(root);
    while(!((*next).empty())){
        vector<int> tmp_vec;
        treeNodeStack* tmp_queue = current;
        current = next;
        next = tmp_queue;
        while(!((*current).empty())){
            TreeNode* tmp = (*current).front();
            (*current).pop();
            tmp_vec.push_back(tmp->val);
            if(tmp->left){
                (*next).push(tmp->left); 
            }
            if(tmp->right){
                (*next).push(tmp->right);
            }
        }
    }
    vector< vector<int> > new_result(result.rbegin(),result.rend());
    return new_result;
}



int main(int argc,char* argv[])
{
    return 0;
}
