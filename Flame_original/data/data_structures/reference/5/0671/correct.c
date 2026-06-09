#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s1[5000], s2[5000];
int x[500], n[500], index[500];
typedef struct NODE
{
	int x;
	int n;
	struct NODE *link;
}node;
node* creatlist()
{
	node *head;
	head = (node*)malloc(sizeof(node));
	head->link = NULL;
	return head;
}
node* creatNode(node *front, int x, int n)
{
	node *pnode;
	pnode = (node*)malloc(sizeof(node));
	pnode->x = x;
	pnode->n = n;
	front->link = pnode;
	pnode->link = NULL;
	return pnode;
}
int cmp(const void *a, const void *b)
{
	int aa = *(int*)a, bb = *(int*)b;
	if(n[aa] >= n[bb])
		return -1;
	else 
		return 1;
}

int main()
{
	node tempnode, *head1, *head2, *p, *q;
	char *p1 = s1;
	int i, j = 0, k;
	gets(s1);
	gets(s2);
	head1 = creatlist();
	head2 = creatlist();
	p = head1;
	q = head1;
	while(sscanf(p1,"%d%d", &tempnode.x, &tempnode.n)!=EOF)
	{
		for(i = 1; tempnode.x/i != 0; i*=10)
			j++;
		for(i = 1; tempnode.n/i != 0; i*=10)
			j++;
		p1+=(j+2);
		q = p;
		p = creatNode(q, tempnode.x, tempnode.n);
		j = 0;
	}
	p1 = s2;
	p = q = head2;
	while(sscanf(p1,"%d%d", &tempnode.x, &tempnode.n)!=EOF)
	{
		for(i = 1; tempnode.x/i != 0; i*=10)
			j++;
		for(i = 1; tempnode.n/i != 0; i*=10)
			j++;
		p1+=(j+2);
		q = p;
		p = creatNode(q, tempnode.x, tempnode.n);
		j = 0;
	}
	p = head1->link;
	q = head2->link;
	i = 0;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			x[i] = p->x * q->x;
			n[i] = p->n + q->n;
			i++;
			q = q->link;
		}
		q = head2->link;
		p = p->link;
	}
	for(i = 0; x[i] != 0; i++)
		index[i] = i;
	if(i>1)
		qsort(index, i, sizeof(int), cmp);
	for(j = 0; j < i; j++)
	{
		if(n[index[j]] == n[index[j+1]]&&j < i-1)
		{
			for(k = 1; n[index[j]] == n[index[j+k]]; k++)
			{
				x[index[j]]+=x[index[j+k]];
				x[index[j+k]] = 0;
			}
			j+=(k-1);	
		}
	}
	for(j = 0; j < i; j++)
	{
		if(x[index[j]])
			printf("%d %d ", x[index[j]], n[index[j]]);
	}
	return 0;
}

