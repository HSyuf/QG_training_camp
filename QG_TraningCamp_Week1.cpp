// QG_TraningCamp_Week1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



using namespace std;


typedef struct list_single{
	int v;
	struct list_single* next;
} LinkList_single;

LinkList_single* createSingleList(int n) {
	LinkList_single* head, *curNode, *preNode;

	if (n <= 0)	return NULL;

	head = (LinkList_single*)malloc(sizeof(LinkList_single));
	curNode = (LinkList_single*)malloc(sizeof(LinkList_single));
	head->next = curNode;
	curNode->next = NULL;
	curNode->v = 1;

	if (n == 1) {
		return head;
	}

	for (int i = 1; i < n; i++) {
		preNode = curNode;
		curNode = (LinkList_single*)malloc(sizeof(LinkList_single)); 
		preNode->next = curNode;
		curNode->next = NULL;
		curNode->v = i + 1;
	}

	return head;
}

void ListOutput(LinkList_single* head) {
	LinkList_single* node = head;
	if (!node || !node->next)	return;

	node = node->next;
	while (node != NULL) {
		printf("%d ", node->v);
		node = node->next;
	}

	putchar(10);

	return;
}

int main()
{
	LinkList_single* headSingle;
	int n;
	scanf("%d", &n);

	headSingle = createSingleList(n);
	ListOutput(headSingle);

	return 0;
}