#include "DulinkedList.h";


int main() {
	ElemType a;
	DuLinkedList head;

	if (!InitList_DuL(&head))
		cout << "Get headNode fail" << "\n";

	while (cin >> a) {//插入新节点，并测试InsertAfterList_DuL函数,CTRL + Z结束
		DuLinkedList newnode = (DuLinkedList)malloc(sizeof(DuLNode));
		newnode->data = a;
		InsertAfterList_DuL(head, newnode);
	}

	//检查输入的数据,并测试TraverseList_DuL函数
	TraverseList_DuL(head, printNodeEl);
	putchar(10);

	//测试DeleteList_DuL函数
	DeleteList_DuL(head, &a);
	TraverseList_DuL(head, printNodeEl);
	putchar(10);

	//测试InsertBeforeList_DuL函数
	DuLinkedList newnode = (DuLinkedList)malloc(sizeof(DuLNode));
	newnode->data = a;
	InsertBeforeList_DuL(head->next, newnode);
	
	TraverseList_DuL(head, printNodeEl);
	putchar(10);

	//执行DestroyList_DuL函数
	DestroyList_DuL(&head);
	cout << "The list is destroyed successfully" << "\n";

	system("pause");

	return 0;
}