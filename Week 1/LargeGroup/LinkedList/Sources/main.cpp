#include "linkedList.h";

int main(){
	ElemType a;
	LinkedList head;

	if (!InitList(&head))
		cout << "Get headNode fail" << "\n";

	while (cin >> a) {//插入新节点，并测试InsertList函数,CTRL + Z结束
		LinkedList newnode = (LinkedList)malloc(sizeof(LNode));
		newnode->data = a;
		InsertList(head, newnode);
	}

	//检查输入的数据
	TraverseList(head, printNodeEl);
	putchar(10);

	//这部分是为了检查SearchList函数在成功检索的情况的运行状况
	if (SearchList(head, a))
		cout << "The element can be found" << "\n";
	else
		cout << "The element can't be found" << "\n";

	//这部分是为了检查SearchList函数在失败检索的情况的运行状况，和DeleteList的运行状况
	DeleteList(head, &a);
	TraverseList(head, printNodeEl);
	putchar(10);

	if (SearchList(head, a))
		cout << "The element can be found" << "\n";
	else
		cout << "The element can't be found" << "\n";

	//这部分是为了测试ReverseList函数
	ReverseList(&head);
	TraverseList(head, printNodeEl);
	putchar(10);

	//测试FindMidNode
	LinkedList midNode = FindMidNode(&head);
	cout << "这个链表的中间结点的值为:" << midNode->data << "\n";

	//测试ReverseEvenList函数
	ReverseEvenList(&head);
	TraverseList(head, printNodeEl);

	//测试IsLoopList函数
	if (IsLoopList(head))
		cout << "The list is loopList" << "\n";
	else
		cout << "The list is not loopList" << "\n";

	//执行DestroyList函数
	DestroyList(&head);
	cout << "The list is destroyed successfully" << "\n";

	system("pause");

	return 0;
}