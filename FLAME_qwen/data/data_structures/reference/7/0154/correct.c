#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include<math.h>
//#define Datatype int   
//#define LinkDatatype int
//#define maxsize 100
//#define maxnumber 14
//#define N 4
//#define maxlen 100
//#define left(a,b) pixel[a][b-1]
//#define right(a,b) pixel[a][b+1]
//#define up(a,b) pixel[a-1][b]
//#define down(a,b) pixel[a+1][b]
//#define M 3
//#define max 99999
////顺序栈
//typedef struct {
//	Datatype data[maxsize];
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
//void push(Seqstack* S,Datatype num) {
//	S->top++;
//	S->data[S->top] = num;
//}
//void pop(Seqstack* S)
//{
//		S->top--;
//}
//Datatype gettop(Seqstack* s) {
//	return s->data[s->top];
//}
////顺序循环队列
//typedef struct {
//	Datatype data[maxlen];
//	int front;
//	int rear;
//}seqqueue;
//seqqueue* setqueue() {
//	seqqueue* q;
//	q = (seqqueue*)malloc(sizeof(seqqueue));
//	q->front = 0;
//	q->rear = 0;
//	return q;
//}
//int queuefull(seqqueue* q) {
//	if (q->front == (q->rear + 1) % maxlen)
//		return 1;
//	else return 0;
//}
//int queueempty(seqqueue* q) {
//	if (q->front == q->rear)
//		return 1;
//	else return 0;
//}
//void add(seqqueue* q, Datatype x) {
//	if (!queuefull(q)) {
//		q->rear == (q->rear + 1) % maxlen;
//		q->data[q->rear] = x;
//	}
//	else printf("queue full");
//}
//void delete (seqqueue* q) {
//	if (!queueempty(q)) 
//		q->front = (q->front + 1) % maxlen;
//	else printf("queue empty");
//}
////链队列
//typedef struct node {
//	int data;
//	struct node* next;
//}linklist;
//typedef struct {
//	linklist* front, * rear;
//}linkqueue;
//linkqueue* setqueue(){
//	linkqueue* q;
//	q = (linkqueue*)malloc(sizeof(linkqueue));
//	q->front = (linklist*)malloc(sizeof(linklist));
//	q->front->next =NULL;
//	q->rear = q->front;
//	return q;
//}
//int queueempty(linkqueue* q) {
//	if (q->front == q->rear)return 1;
//	else return 0;
//}
//linkqueue* add(linkqueue* q, int num) {
//	linklist* p;
//	p = (linklist*)malloc(sizeof(linklist));
//	p->data = num;
//	p->next = NULL;
//	q->rear->next = p;
//	q->rear = p;
//	return q;
//}
//linkqueue* delete(linkqueue* q) {
//	linklist* p;
//	if (!queueempty(q)) {
//		p = q->front->next;
//		q->front->next = p->next;
//		if (p->next == NULL)
//			q->rear = q->front;
//		free(p); return q;
//	}
//	else printf("queue empty");
//}
typedef struct bitree {
	int root;
	struct bitree* left;
	struct bitree* right;
}bitree;
bitree* planttree() {
	bitree* bt = (bitree*)malloc(sizeof(bitree));
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}
void printleaf(bitree* bt, int height) {
	if ((!bt->left) &&( !bt->right))
		printf("%d %d\n", bt->root,height);
	else {
		if (bt->left)
			printleaf(bt->left,height+1);
		if (bt->right)
			printleaf(bt->right,height+1);
	}
}
int main() {
	int n;
	scanf("%d", &n);getchar();
	bitree* bt = planttree();
	scanf("%d", &bt->root);
	//char c = getchar();
	int x; bitree* pt;
	while (scanf("%d",&x)!=EOF) {
 		pt = bt;
		//scanf("%d", &x);
		while (pt&&(pt->left || pt->right)) {
			if (x >= pt->root)
			{
				if (pt->right)
					pt = pt->right;
				else break;
			}
			else {
				if (pt->left)
					pt = pt->left;
				else break;
			}
		}
			bitree* leaf = (bitree*)malloc(sizeof(bitree));
			leaf->root = x;
			leaf->left = leaf->right = NULL;
			if (x >= pt->root)
				pt->right = leaf;
			else
				pt->left = leaf;
		//c = getchar();
	}
	printleaf(bt,1);
	return 0;
}
