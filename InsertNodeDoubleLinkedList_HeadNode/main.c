//
//  main.c
//  InsertNodeDoubleLinkedList_HeadNode
//
//  Created by chenyufeng on 16/3/4.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  往带头结点尾结点的双向非循环链表中插入一个节点
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表
void CreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}

//正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }
    
    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//插入一个节点
//插入位置分别为0,1,2,.....
int InsertNodeList(Node *pHead,Node *pTail,int pos,int x){

    int i = 0;
    Node *pMove;
    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;
    pInsert->element = x;

    pMove = pHead;
    while (pMove != pTail) {
        if (i == pos) {
            //注意这里的链接顺序
            pMove->next->prior = pInsert;
            pInsert->next = pMove->next;
            pMove->next = pInsert;
            pInsert->prior = pMove;

            printf("%s函数执行，在pos=%d位置插入x=%d节点成功\n",__FUNCTION__,pos,x);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，插入元素失败\n",__FUNCTION__);

    return 0;
}


int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);

    CreateList(pHead, pTail);
    PrintList(pHead, pTail);

    InsertNodeList(pHead,pTail,5,1111);
    PrintList(pHead, pTail);

    return 0;
}
