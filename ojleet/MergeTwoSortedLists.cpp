/*************************************************************************
	> File Name: MergeTwoSortedLists.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日 10/11 23:18:54 2015
 ************************************************************************/
mZ#include<iostream>
#include<string>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l2->val < l1->val){
            ListNode* tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode* p = l1;
        ListNode* q = l1;
        while(l1 && l2){
            if(l1->val < l2->val){
                q = l1;
                l1 = l1->next;
            }
            else{
                q->next = l2; 
                l2 = l2->next;
                q->next->next = l1;
                q = q->next;
            }
        }
        if(l2){
            q->next = l2;
        }
        return p;
        
    }
    
    ListNode* mergeTwoLists_2(ListNode* l1,ListNode* l2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(l1!=NULL || l2!= NULL)
        {
            int val1 = l1==NULL?INT_MAX:l1->val;
            int val2 = l2==NULL? INT_MAX:l2->val;
            if(val1<=val2)
            {
                p->next = l1;
                l1=l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                
            }
            p= p->next;
        }
        p = head->next;
        delete head;
        return p;
    }
};
int main(int argc,char* argv)
{
    return 0;
}
