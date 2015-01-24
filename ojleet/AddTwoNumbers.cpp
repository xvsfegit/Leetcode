/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月24日 星期六 18时23分51秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include"ListNode.h"
using namespace std;
class Solution {
public:
    int getListLen(ListNode* head)
    {
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
    void getL2Value(ListNode* head,vector<int>& NodeValue)
    {
        while(head){
            NodeValue.push_back(head->val);
            head = head->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        int l1Len = getListLen(l1);
        int l2Len = getListLen(l2);
        if(l1Len < l2Len){
            swap(l1,l2);
        }
        ListNode* start = l1;
        ListNode* end = NULL;
        int flag = 0;
        while(l1){
            int tmpValue = 0;
            if(l2){
                tmpValue = l1->val + l2->val + flag;
                l2 = l2->next;
            }
            else{
                tmpValue = l1->val + flag;
            }
            l1->val = tmpValue % 10;
            flag = tmpValue / 10;
            end = l1;
            l1 = l1->next;
        }
        if(flag){
            end->next = new ListNode(flag);
        }
        return start;
    }
};
int main(int argc,char* argv[])
{
    return 0;
}
