#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include<math.h>
//#define Datatype char   
//#define maxsize 10000
//int getword(char* line, int* i, char* des) {
//	char r[100];
//	int j = 0;
//	int k = *i;
//	while (line[k] && (line[k] < 'A' || line[k]>'z' || line[k] > 'Z' && line[k] < 'a'))
//		k++;
//	if (!line[k])return 0;
//	while (line[k] >= 'A' && line[k] <= 'Z' || line[k] >= 'a' && line[k] <= 'z')
//		r[j++] = tolower(line[k++]);
//	r[j] = '\0';
//	*i = k;
//	strcpy(des, r);
//	return 1;
//}
//int main() {
//	FILE* fp = fopen("edits.txt", "r");
//	char word[100], line[1024];
//	char symbol[15];
//	char sample[] = "news";
//	
//	while (fgets(symbol, 15, fp)) {
//		int num = 0;
//		while (fgets(line, 1024, fp)) {
//			if (line[0] == '\f')
//				break;
//			int  i = 0;
//			while (getword(line, &i, word)) {
//				num++;
//			}
//		}
//		printf("%d\n", num);
//	}
//	
//	return 0;
//}
//#define Datatype int 
//#define maxsize 150 
//typedef struct {
//	void* data[256];
//	int top;
//}Seqstack;
//Seqstack* SetStack() {
//	Seqstack* S;
//	S = (Seqstack*)malloc(sizeof(Seqstack));
//	S->top = -1;
//	return S;
//}
//int StackEmpty(Seqstack* S) {
//	if (S->top >= 0)return 0;
//	else return 1;//栈空时返回1，不空返回0
//}
//int StackFull(Seqstack* S) {
//	if (S->top < maxsize - 1 && S->top >= -1)
//		return 0;
//	else return 1;//栈满时返回1，不满返回0
//}
//void* gettop(Seqstack* S) {
//	if (S->top <= maxsize - 1 && S->top >= 0)
//		return S->data[S->top];
//	else printf("error");
//}
//void push(Seqstack* S, void* node) {
//	if (S->top < maxsize - 1 && S->top >= -1)
//	{
//		S->top++;
//		S->data[S->top] = node;
//	}
//	else printf("error");
//}
//void pop(Seqstack* S)
//{
//	if (S->top >= 0)
//		S->top--;
//	else printf("error");
//}
//typedef struct bitree {
//	double val;
//	char op;
//	struct bitree* left;
//	struct bitree* right;
//}bitree;
//int inferior(char a, char b) {
//	if (a == '(')return 1;
//	if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '%'))
//		return 1;
//	else return 0;
//}//a弱于b
//int leaf(bitree* bt) {
//	if (bt->left == bt->right && bt->left == NULL)
//		return 1;
//	else return 0;
//}
//void traverse(bitree* bt) {
//	if (!leaf(bt->left))
//		traverse(bt->left);
//	if (!leaf(bt->right))
//		traverse(bt->right);
//	switch (bt->op)
//	{
//	case '+': bt->val = 1.0*bt->left->val + bt->right->val; break;
//	case '-': bt->val = 1.0*bt->left->val - bt->right->val; break;
//	case '*': bt->val = 1.0*bt->left->val * bt->right->val; break;
//	case '/': 
//		if (fabs(bt->right->val) < 1e-30)
//			printf("awxcc\n");
//		else 
//		bt->val = 1.0*bt->left->val / bt->right->val; break;
//	default:
//		break;
//	}
//	bt->left = bt->right = NULL;
//}
//int height(bitree* bu,int depth) {
//	if (leaf(bu))
//		return depth + 1;
//	else if (bu->left && !bu->right)
//	{
//		return height(bu->left, depth + 1);
//	}
//	else if (!bu->left && bu->right)
//	{
//		return height(bu->right, depth + 1);
//	}
//	else return height(bu->left, depth + 1) > height(bu->right, depth + 1) ? height(bu->left, depth + 1) : height(bu->right, depth + 1);
//}
//int main() {
//	char formla[300];
//	gets(formla);
//	Seqstack* ndstk = SetStack();
//	Seqstack* opstk = SetStack();
//	int i = 0; char w; bitree* ppp;
//	if (formla[1] == '=')
//	{
//		printf("%d\n0", formla[0]-'0');
//		return 0;
//	}
//	while (formla[i] != '=') {
//		if (formla[i] <= '9' && formla[i] >= '0') {
//			int a = 0;
//			while (formla[i] <= '9' && formla[i] >= '0')
//			{
//				a = a * 10 + formla[i] - '0';
//				i++;
//			}
//			bitree* bt = (bitree*)malloc(sizeof(bitree));
//			bt->left = bt->right = NULL;
//			bt->val = a;
//			bt->op = '\0';
//			push(ndstk, (void*)bt);
//			ppp = (bitree*)gettop(ndstk);
//		}
//		else if (formla[i] == '(') {
//			char* s = &formla[i++];
//			push(opstk, (void*)s);
//		}
//		else {
//			if (StackEmpty(opstk))
//			{
//				char* s = &formla[i++];
//				push(opstk, (void*)s);
//			}
//			else
//			{
//				char cc = *((char*)gettop(opstk));
//				while (!inferior(cc, formla[i])) {
//					bitree* a, * b;
//					b = (bitree*)gettop(ndstk);
//					pop(ndstk);
//					a = (bitree*)gettop(ndstk);
//					pop(ndstk);
//					bitree* c = (bitree*)malloc(sizeof(bitree));
//					c->left = a;
//					c->right = b;
//					c->op = cc;
//					push(ndstk, (void*)c);
//					ppp = (bitree*)gettop(ndstk);
//					pop(opstk);
//					if (StackEmpty(opstk))
//						break;
//					cc = *((char*)gettop(opstk));
//				}
//				if (!StackEmpty(opstk) && cc == '(' && formla[i] == ')')pop(opstk);
//				else push(opstk, (void*)(&formla[i]));
//				i++;
//			}
//		}
//		if (!StackEmpty(opstk))
//			w = *((char*)gettop(opstk));
//	}
//	while (!StackEmpty(opstk)) {
//		char cc = *((char*)gettop(opstk));
//		bitree* a, * b;
//		b = (bitree*)gettop(ndstk);
//		pop(ndstk);
//		a = (bitree*)gettop(ndstk);
//		pop(ndstk);
//		bitree* c = (bitree*)malloc(sizeof(bitree));
//		c->left = a;
//		c->right = b;
//		c->op = cc;
//		push(ndstk, (void*)c);
//		ppp = (bitree*)gettop(ndstk);
//		pop(opstk);
//	}
//	bitree* bu = (bitree*)gettop(ndstk);
//	int h = height(bu,0)-1;
//	traverse(bu);
//	if (bu->val > 0)
//	{
//		if((bu->val-(int)bu->val)>=0.50)
//		printf("%d\n", (int)(bu->val)+1);
//		else 	printf("%d\n", (int)(bu->val));
//	}
//	else if (fabs(bu->val) < 1e-12)
//		printf("0\n");
//	else {
//		double t = -(bu->val);
//		if ((t - (int)t) >= 0.50)
//			printf("-%d\n", ((int)t + 1));
//		else 	printf("-%d\n", (int)(t));
//	}
//	printf("%d", h);
//	return 0;
//}
#define  Datatype int
#define maxlen 105
typedef struct {
	Datatype data[maxlen];
	int front;
	int rear;
}seqqueue;
seqqueue* setqueue() {
	seqqueue* q;
	q = (seqqueue*)malloc(sizeof(seqqueue));
	q->front = 0;
	q->rear = 0;
	return q;
}
int queuefull(seqqueue* q) {
	if (q->front == (q->rear + 1) % maxlen)
		return 1;
	else return 0;
}
int queueempty(seqqueue* q) {
	if (q->front == q->rear)
		return 1;
	else return 0;
}
void add(seqqueue* q, Datatype x) {
	if (!queuefull(q)) {
		q->rear = (q->rear + 1) % maxlen;
		q->data[q->rear] = x;
	}
	else printf("queue full");
}
void delete (seqqueue* q) {
	if (!queueempty(q)) 
		q->front = (q->front + 1) % maxlen;
	else printf("queue empty");
}

visit[105];
int vn, en;
void dfstraverse(int graph[][105],int i) {
	visit[i] = 1;
	printf("%d ", i);
	for (int j = 0; j < vn; j++)
		if (!visit[j]&&graph[i][j])
			dfstraverse(graph, j);
}
void bfstraverse(int graph[][105],int i) {
	seqqueue* q = setqueue();
	add(q, i);
	visit[i] = 1;
	while (!queueempty(q)) {
		int t = q->data[(q->front+1)%maxlen];
		printf("%d ", t);
		delete(q);
		for (int j = 0; j < vn; j++)
			if (graph[t][j]&&!visit[j])
			{
				add(q, j);
				visit[j] = 1;
			}
	}
}
int main() {
	int graph[105][105] = { 0 };

	scanf("%d%d", &vn, &en);
	int i1, i2;
	for (int i = 0; i < en; i++)
	{
		scanf("%d%d", &i1, &i2);
		graph[i1][i2] = graph[i2][i1] = 1;
	}
	int depoint;
	scanf("%d", &depoint);
	memset(visit, 0, 105);
	dfstraverse(graph,0);
	printf("\n");
	memset(visit, 0, 105);
	bfstraverse(graph,0);
	printf("\n");
	for (int i = 0; i < vn; i++)
	{
		graph[i][depoint] = 0;
		graph[depoint][i] = 0;
	}
	memset(visit, 0, 105);
	dfstraverse(graph,0);
	printf("\n");
	memset(visit, 0, 105);
	bfstraverse(graph,0);
	printf("\n");
	return 0;
}
