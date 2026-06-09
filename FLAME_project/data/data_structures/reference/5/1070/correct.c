#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define xishu 0
#define Mi 1

typedef struct ListNode {
    int xs;
	int m;
    struct ListNode *next;
} ListNode;

typedef struct LinkList {
    ListNode head;
    int length;
} LinkList;

ListNode *init_listnode(int val1, int val2) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->xs = val1;
    p->m = val2;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_listnode(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_linklist(LinkList *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return ;
}

void insert(LinkList *l, int ind, int val1, int val2) {
    if (l == NULL) return ;
    if (ind < 0 || ind > l->length) return ;
    ListNode *p = &(l->head), *node = init_listnode(val1, val2);
    while (ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return ;
}

int **getnumber(char *str, int *a1)
{
	int length = strlen(str);
	int **a = (int **) malloc (sizeof(int *) * 1000);
	int i = 0;
	for(i = 0; i < 1000; i++) {
		a[i] = (int *) malloc (sizeof(int) * 3);
	}
	//申请二维数组完成 
	int flag = 0;
	int bit = 1;
	int sum = 0;
	int k = 0;//记录多项式中有几个单项式 
	for(i = 0; i < length; i++){
		if(str[i] == ' ') continue;
		if(flag == 0) {
			int j = i;
			while(str[j] >= '0' && str[j] <= '9' && j < length) j++;
			int jump = j;
			j--;
			for(j; j >= i; j--){
				sum += (str[j] - '0') * bit;
				bit *= 10;
			}
			a[k][xishu] = sum;
			sum = 0;
			bit = 1;
			flag = 1;
			i = jump;
			continue;
		}
		if(flag == 1) {
			int j = i;
			while(str[j] >= '0' && str[j] <= '9' && j < length) j++;
			int jump = j;
			j--;
			for(j; j >= i; j--){
				sum += (str[j] - '0') * bit;
				bit *= 10;
			}
			a[k][Mi] = sum;
			sum = 0;
			bit = 1;
			flag = 0;
			i = jump;
			k++;
		}
	}
	*a1 = k;
	return a;
}

void multi(LinkList *final, LinkList *l1, LinkList *l2)
{
	ListNode *p1 = l1->head.next;
	ListNode *p2 = l2->head.next;
	while(p1 != NULL){
		while(p2 != NULL){
			int newxishu = (p1->xs) * (p2->xs), newmi = (p1->m) + (p2->m);
			if(final->length == 0)  {
				insert(final, 0, newxishu, newmi);
				p2 = p2->next;	
				continue;
			}
			int i = 0;
			ListNode *p = final->head.next;
			
			while(p->m > newmi && p != NULL) {
				p = p->next;
				i++;
				if(p == NULL) break;
			}
			if(p == NULL) {
				insert(final, i, newxishu, newmi);
				p2 = p2->next;
				continue;
			}
			if(p->m == newmi) {
				p->xs += newxishu;
			}
			else {
				insert(final, i, newxishu, newmi);
			}
			p2 = p2->next;
		}
		p2 = l2->head.next;
		p1 = p1->next;
	}
	return ;
}

void output(LinkList *final) {
	int i = 0;
	ListNode *p = final->head.next;
	for(i = 0; i < final -> length; i++) {
		printf("%d %d ", p->xs, p->m );
		p = p->next; 
	}
	return ;
}

int main()
{
	char str1[1000];
	char str2[1000];
	gets(str1);
	gets(str2);
	int length_1 = 0;
	int length_2 = 0; 
	int **multi_1 = getnumber(str1, &length_1);
	int **multi_2 = getnumber(str2, &length_2);
	LinkList *l1 = init_linklist();
	LinkList *l2 = init_linklist();
	int i = 0;
	for(i = 0; i < length_1; i++) {
		insert(l1, i, multi_1[i][xishu], multi_1[i][Mi]);
	}
	for(i = 0; i < length_2; i++) {
		insert(l2, i, multi_2[i][xishu], multi_2[i][Mi]);
	}
	LinkList *final = init_linklist();
	multi(final, l1, l2);
	output(final);
	clear_linklist(l1);
	clear_linklist(l2);
	clear_linklist(final);
	return 0;
}




