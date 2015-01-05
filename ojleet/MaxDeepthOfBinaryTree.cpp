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
int maxDepth(TreeNode* currentNode)
{
    if(currentNode == NULL)
        return 0;
    int maxDepth= 0;
    int layer = 0;
    int flag = 0;
    stack<TreeNode*> remainNode;
    while(1){
        if(currentNode == NULL){
            if(remainNode.empty()){
                break;
            }    
            layer = flag;
            currentNode = remainNode.top();
            remainNode.pop();
            --flag;
            currentNode = currentNode->right;
        }
        else{
            ++layer;
            if(layer > maxDepth){
                maxDepth = layer;
            }
            remainNode.push(currentNode);
            ++flag;
            currentNode = currentNode->left;
        }
    }
    return maxDepth; 
}

int main(int argc,char* argv[])
{
    TreeNode* p = new TreeNode(0);
    //p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    //p->left->left = new TreeNode(3);
    cout << maxDepth(p) << endl;
    return 0;
}
