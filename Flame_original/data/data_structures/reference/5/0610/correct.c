#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
#define max 200
struct  node { //一个多项式节点结构
    int num; //系数
    int index; //幂
    struct node *next;
};
struct node * insertNode(struct node * head, long long num, long long index)
{
	struct node * p = head, *q = NULL, *r = NULL;
	r = (struct node *)malloc(sizeof(struct node));
	r->num = num;
	r->index = index;
	r->next = NULL;
	if (head == NULL)
		return r;
	for (p = head; p != NULL && p->index > index; q = p, p = p->next)
		;
	if (p != NULL && p->index == index)
	{
		p->num += num;
	}
	else if (p == head)
	{
		r->next = p;
		return r;
	}
	else
	{
		q->next = r;
		r->next = p;
	}
	return head;
}
int main()
{
	/*FILE *fp1;//定义文件指针 
	fp1 = fopen("filein.txt","r");//r为读 
	FILE *fp2; //定义文件指针 
	fp2 = fopen("fileout.txt","w");//w为写 
	fclose(fp1);
	fclose(fp2);*/
/*	struct node *head,*p,*q,*p0;
	head = p = NULL;
    struct node * line = NULL,* ans = NULL;
	long long num, index, tmp = 20000000000;
	while ((scanf("%lld%lld", &num, &index)) != EOF)
	{
		if (tmp <= index)
		{
			struct node * p = NULL;
			for (p = line; p != NULL; p = p->next)
			{
				ans = insertNode(ans, (p->num) * num, (p->index) + index);
			}
			break;
		}
		line = insertNode(line, num, index);
		tmp = index;		
	}
	/*while ((scanf("%lld%lld", &num,&index)) != EOF)
	{
		struct node * q = NULL;
		for (q=line; q!= NULL; q=q->next)
		{
			ans=insertNode(ans, num * q->num, index + q->index);
		}
	}*/
    struct node * line = NULL, *ans = NULL;
	long long num, index, tmp = 20000000000;
	while ((scanf("%lld%lld", &num, &index)) != EOF)
	{
		if (tmp <= index)
		{
			struct node * p = NULL;
			for (p = line; p != NULL; p = p->next)
			{
				ans = insertNode(ans, (p->num) * num, (p->index) + index);
			}
			break;
		}
		line = insertNode(line, num, index);
		tmp = index;
	}
	while ((scanf("%lld%lld", &num, &index)) != EOF)
	{
		struct node * q = NULL;
		for (q = line; q != NULL; q = q->next)
		{
			ans = insertNode(ans, num * q->num, index + q->index);
		}
	}
	struct node * p;
    for(p=ans; p!=NULL; p=p->next)
         printf("%d %d ", p->num,p->index);
	return 0;	
 }




