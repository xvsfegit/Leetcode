/*************************************************************************
	> File Name: SwapNodesInPairs.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 四 12/10 22:35:35 2015
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* e_head = new ListNode(-1);
        e_head->next = p;
        ListNode* r = e_head;
        while(p && p->next){ 
            q = p->next;
            p->next = q->next;
            q->next = p;
            r->next = q;
            r = p;
            p = r->next;
        }
        return e_head->next;
    }

};


int main(int argc,char* argcv[])
{
    ListNode node_1(1);
    ListNode node_2(2);
    node_1.next = &node_2;
    ListNode node_3(3);
    node_2.next = &node_3;
    ListNode node_4(4);
    //node_3.next = &node_4;
    
    Solution testClass;
    ListNode* test = testClass.swapPairs(&node_1);
    while(test){
        std::cout << test->val << std::endl; 
        test = test->next;
    }
    return 0;
}
