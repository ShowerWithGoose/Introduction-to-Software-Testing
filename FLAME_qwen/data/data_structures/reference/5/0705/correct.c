#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807（>10^18）   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

struct num
{
	ll num1;
	ll num2;
}numx[4000],numy[4000];
typedef struct ans
{
	ll ans1;
	ll ans2;
	struct ans *next;
}linkList;
linkList *create(ll n);
void insert(linkList *list, ll n,ll a1,ll a2);

int main()
{
	ll i,ansx1,ansx2,numx1,numy1,flag,flag1;
	linkList *head=NULL;
	linkList *temp=NULL;
	linkList ins;
	i=0;
	scanf("%lld %lld",&numx[i].num1,&numx[i].num2);
	while(getchar()!='\n')
	{
		i+=1;
		scanf("%lld %lld",&numx[i].num1,&numx[i].num2);
	}
	numx1=i+1;
	i=0;
	scanf("%lld %lld",&numy[i].num1,&numy[i].num2);
	while(getchar()!='\n')
	{
		i+=1;
		scanf("%lld %lld",&numy[i].num1,&numy[i].num2);
	}
	numy1=i+1;
	head=create(numy1);
	temp=head;
	for(int k=1;k<numx1;k++)
	{
	    for(int j=0;j<numy1;j++)
	    {
	    	flag1=0;
	    	flag=1;
	    	temp=head;
	    	ansx1=numx[k].num1*numy[j].num1;
	    	ansx2=numx[k].num2+numy[j].num2;
	    	while(temp->next!=NULL)
	    	{
	    		temp=temp->next;
	    		if(temp->ans2>ansx2)
	    		{
	    			flag+=1;
				}
				else if(temp->ans2==ansx2)
				{
					temp->ans1+=ansx1;
					flag1=1;
				}
				else
				{
					insert(head,flag-1,ansx1,ansx2);
					flag1=1;
				}
				if(flag1==1) 
				{
					goto out;
				}
			}
			out:
			if(temp->next==NULL&&flag1==0)
			{
				insert(head,flag-1,ansx1,ansx2);
			}
		}
	}
	temp=head;
	while (temp->next!= NULL) 
	{
        temp = temp->next;
        printf("%lld %lld ",temp->ans1,temp->ans2);
    }
	
} 
linkList *create(ll n)
{
	linkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (linkList*)malloc(sizeof(linkList));//分配地址
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) 
	{
		node = (linkList*)malloc(sizeof(linkList));
		node->ans1=numx[0].num1*numy[i].num1;
		node->ans2=numx[0].num2+numy[i].num2;
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}
void insert(linkList *list, ll n,ll a1,ll a2) {
	linkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in = (linkList*)malloc(sizeof(linkList));
		in->ans1=a1;
		in->ans2=a2;
		in->next = t->next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
		t->next = in;//填充t节点的指针域，把t的指针域重新指向in
	}
	else {
		puts("节点不存在");
	}
}


