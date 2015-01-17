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
/*
 */
int maxDepth(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    int maxDepth= 0;
    int layer = 0;
    TreeNode* currentNode = root;
    stack<TreeNode*> remainNode;
    while(1){
        ++layer;        
        if(currentNode->left){
            remainNode.push(currentNode);
            currentNode = currentNode->left;
            continue;
        }
        if(currentNode->right){
            remainNode.push(currentNode);
            currentNode = currentNode->right;
            continue;
        }
        if(layer > maxDepth){
            maxDepth = layer;
        }
        --layer;
        if(remainNode.empty())
            break;
        currentNode = remainNode.top();
        remainNode.pop();
    }
    return maxDepth; 
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    cout << maxDepth(p) << endl;
    return 0;
}
