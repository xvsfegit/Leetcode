/*************************************************************************
	> File Name: removeNodeFromEnd.cpp
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com 
	> Created Time: 日 12/21 19:40:02 2014
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* removeNthFromEnd(ListNode* head,int n)
{
    if(head == NULL)
        return head;
    ListNode* hopeEnd = head;
    int count = 0;
    while(hopeEnd){
        ++count;
        hopeEnd = hopeEnd->next;
    }
    int pos = count - n;
    hopeEnd = head;
    if(pos == 0){
        head = head->next;
        delete hopeEnd;
    }else if(pos > 0){
        pos = pos - 1;
        while(pos-- > 0){
            hopeEnd = hopeEnd->next;
        }
        ListNode* tmp = hopeEnd->next;
        hopeEnd->next = tmp->next;
        delete tmp;
    }
    return head;

}
int main(int argc,char* argv[])
{
    cout << "Please input the number:";
    int n;
    cin >> n;
    cout << "Please input the Nth:";
    int nth;
    cin >> nth;
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for(int i = 1;i < n; ++i){
        p->next = new ListNode(i);     
        p = p->next;
    }
    head = removeNthFromEnd(head,nth);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
