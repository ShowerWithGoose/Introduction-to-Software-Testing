#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	long long num;
	long long mini;
	struct node *next;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr insertNode(Nodeptr head, long long num, long long mini)
{
	Nodeptr m = head, n = NULL, r = NULL;
	r = (Nodeptr)malloc(sizeof(Node));
	r->num = num;
	r->mini = mini;
	r->next = NULL;
	if(head == NULL)
		return r;
	for(m = head; m != NULL && m->mini > mini; n = m, m = m->next);
	if (m != NULL && m->mini == mini){
		m->num += num;
	}
	else if (m == head){
		r->next = m;
		return r;
	}
	else{
		n->next = r;
		r->next = m;
	}
	return head;
}
int printNode(Nodeptr head)
{
	if (head == NULL)
		return 0;
	Nodeptr m;
	for (m = head; m != NULL; m = m->next){
		if (m->num != 0){
			printf("%lld ", m->num);
			printf("%lld ", m->mini);
		}
	}
	return 1;
}
int main()
{
	Nodeptr flag = NULL, help = NULL;
	long long num, mini, tmp = 20000000000;
	while ((scanf("%lld%lld", &num, &mini)) != EOF){
		if (tmp <= mini){
			Nodeptr m = NULL;
			for (m = flag; m != NULL; m = m->next){
				help = insertNode(help, (m->num) * num, (m->mini) + mini);
			}
			break;
		}
		flag = insertNode(flag, num, mini);
		tmp = mini;
	}
	while ((scanf("%lld%lld", &num, &mini)) != EOF){
		Nodeptr n = NULL;
		for (n = flag; n != NULL; n = n->next){
			help = insertNode(help, num * n->num, mini + n->mini);
		}
	}
	printNode(help);
	return 0;
}


