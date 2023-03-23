#pragma once
#pragma once
/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/
void printNodeEl(ElemType e) {//自一个测试函数
	cout << e << " ";
}
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
	DuLinkedList newnode = (DuLinkedList)malloc(sizeof(DuLNode));

	if (newnode == NULL)  return ERROR;

	newnode->next = NULL;
	newnode->prior = NULL;
	*L = newnode;

	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList curnode, prenode;

	if (!L) return; //处理输入错误

	curnode = *L;
	while (curnode) {
		prenode = curnode;
		curnode = curnode->next;
		free(prenode);
	}

	return;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (!p || !q) return ERROR;

	q->next = p;
	q->prior = p->prior;
	p->prior = q;

	if (!q->prior)	return SUCCESS;

	q->prior->next = q;

	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (!p || !q) return ERROR;

	q->next = p->next;
	q->prior = p;
	p->next = q;

	if (!q->next)	return SUCCESS;

	q->next->prior = q;

	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (!p) return ERROR;

	*e = p->next->data;
	p->next = p->next->next;
	free(p->next->prior);
	p->next->prior = p;

	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList curNode = L->next;

	while (curNode != NULL) {
		(*visit)(curNode->data);
		curNode = curNode->next;
	}

	return;
}


/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
