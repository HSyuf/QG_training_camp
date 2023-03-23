#pragma once
#pragma once
/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section

**************************************************************/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <numeric>
#define OVERFLOW -1

using namespace std;
const int mod = 998244353;
const int INF = 0x7f7f7f7f;
const int N = 2 * 1e5 + 10;
typedef pair<int, int> PII;
typedef long long ll;
const double PI = 3.1415926;
int dx[] = { -1, 0, 1, 0, 0 }, dy[] = { 0, 1, 0, -1, 0 };
/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/
void printNodeEl(ElemType e) {//自一个测试函数
	cout << e << " ";
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L) {
	LinkedList headNode;

	headNode = (LinkedList)malloc(sizeof(LNode));

	if (!headNode)	return ERROR;
	headNode->next = NULL;

	*L = headNode;

	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) {
	LinkedList curnode, prenode;

	if (!L) return; //处理输入错误

	curnode = prenode = *L;
	while (curnode) {
		prenode = curnode;
		curnode = curnode->next;
		free(prenode);
	}

	return;
}


/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	if (!p || !q)	return ERROR;

	q->next = p->next;
	p->next = q;

	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) {
	if (!p)	return ERROR;

	*e = p->next->data;
	p->next = p->next->next;

	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {//因为头结点可能会被改变成一个有值的节点,所以我还是遍历了头结点
	LinkedList curNode = L->next;

	while (curNode != NULL) {
		(*visit)(curNode->data);
		//printNodeEl(curNode->data);
		curNode = curNode->next;
	}

	return;
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList curNode = L->next;

	while (curNode) {
		if (curNode->data == e) return SUCCESS;
		curNode = curNode->next;
	}

	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {
	LinkedList prenode, curnode, nextnode;

	if (!L) {
		return ERROR; //头结点传入错误
	}

	//初始化
	prenode = NULL;
	curnode = (*L)->next;
	nextnode = (*L)->next->next;

	//这里我看传回去的只是成功与否，所以就拿nextnode来作为评判标准了
	while (nextnode) {
		curnode->next = prenode;
		prenode = curnode;
		curnode = nextnode;
		nextnode = nextnode->next;
	}

	curnode->next = prenode;
	(*L)->next = curnode;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	bool judge = 0;
	LinkedList fastPivot = L, slowPivot = L;

	while (fastPivot->next && fastPivot->next->next) {
		fastPivot = fastPivot->next->next;
		slowPivot = slowPivot->next;

		if (fastPivot == slowPivot) {
			return SUCCESS;//代表是循环的链表
		}
	}

	return ERROR;//代表不是循环的链表
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) {
	LinkedList prenode, curnode, nextnode;

	//因为一开始头结点说没有数据，所以直接从下一个开始
	prenode = (*L);
	curnode = (*L)->next;

	if (!curnode)//处理只有一个头结点的特殊情况
		return NULL;

	nextnode = (*L)->next->next;//处理头结点后第一个结点符合的情况
	if (!(curnode->data & 1)) {
		prenode->next = curnode->next;
		curnode->next = prenode;
		*L = curnode;
	}

	while (nextnode) {
		if (!(nextnode->data & 1)) {
			curnode->next = nextnode->next;
			prenode->next = nextnode;
			nextnode->next = curnode;
		}
		prenode = curnode;
		curnode = nextnode;
		nextnode = nextnode->next;
	}

	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) {
	LinkedList fastPivot = *L, slowPivot = *L;

	while (fastPivot->next) {
		fastPivot = fastPivot->next->next;
		slowPivot = slowPivot->next;
		if (!fastPivot)
			break;
	}

	return slowPivot;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
