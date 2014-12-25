/*************************************************************************
	> File Name: RemoveDupFromSortedList.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2014年12月26日 星期五 04时00分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* p = head;
    while(p && p->next){
        ListNode* q = p->next;
        if(q->val == p->val){
            p->next = q->next;
            delete q;
        }
        else{
            p = p->next;
        
        }
    }
    return head;
}


int main(int argc,char* argv[])
{
    return 0;
}
