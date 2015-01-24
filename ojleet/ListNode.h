/*************************************************************************
	> File Name: ListNode.h
	> Author:Kcn
	> Mail:xvsfekcn@gmail.com
	> Created Time: 2015年01月24日 星期六 18时25分19秒
 ************************************************************************/

#ifndef _LISTNODE_H
#define _LISTNODE_H
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x = 0):val(x),next(NULL){}
};
#endif
