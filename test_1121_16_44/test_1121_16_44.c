//括号匹配问题
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->top = -1;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top + 1 == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->top++;
	pst->a[pst->top] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);

	return pst->a[pst->top];
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top + 1;
}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == -1;
}

bool isValid(char* s)
{
	ST S;
	STInit(&S);

	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			STPush(&S, *s);
		}
		else
		{
			if (STEmpty(&S))
			{
				STDestroy(&S);
				return false;
			}

			char tmp = STTop(&S);
			STPop(&S);
			if ((*s == ']' && tmp != '[')
				|| (*s == ')' && tmp != '(')
				|| (*s == '}' && tmp != '{'))
			{
				STDestroy(&S);
				return false;
			}
		}
		s++;
	}

	bool ret = STEmpty(&S);
	STDestroy(&S);
	return ret;
}

//两个队列实现栈
typedef int QDataType;
//链式结构实现队列--单链表
typedef struct QListNode
{
	QDataType data;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);

	q->front = q->rear = NULL;
	q->size = 0;
}

void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->data = x;
	newnode->next = NULL;

	if (q->rear == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);

	QNode* del = q->front;
	q->front = q->front->next;
	free(del);
	q->size--;
	del = NULL;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);

	return q->front->data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);

	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);

	return q->size;
}
bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->front == NULL;
}


typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* emptyq = &obj->q1;
	Queue* noneempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyq = &obj->q2;
		noneempty = &obj->q1;
	}

	while (QueueSize(noneempty) > 1)
	{
		QueuePush(emptyq, QueueFront(noneempty));
		QueuePop(noneempty);
	}
	int top = QueueFront(noneempty);
	QueuePop(noneempty);
	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}


//栈实现队列
//两个栈，一个专门用来入数据，另一个专门用来出数据
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->top = -1;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top + 1 == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->top++;
	pst->a[pst->top] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	assert((pst->top) > -1);

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert((pst->top) > -1);

	return pst->a[pst->top];
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top + 1;
}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == -1;
}

typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek((obj));
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->popst))
	{
		while (!STEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}

	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);
	free(obj);
}