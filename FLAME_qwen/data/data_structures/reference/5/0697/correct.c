#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define int LL
typedef struct node
{
	int a,b;
	struct node* next;
}NODE;
NODE *x1,*x2,*ans;

void read(NODE* x,char *s1);
char s1[100001],s2[100001];
NODE* newnode(){NODE* re=(NODE*)malloc(sizeof(NODE));re->a=re->b=0;re->next=NULL;return re;}
signed main()
{
	// freopen("data.in","r",stdin);

	x1=newnode();x2=newnode();ans=newnode();
	gets(s1);gets(s2);
	read(x1,s1);read(x2,s2);

	for(;x1->a!=0;x1=x1->next)
		for(NODE* t=x2;t->a!=0;t=t->next)
		{
			NODE* now=ans;
			if(now->a==0){now->a=x1->a*t->a,now->b=x1->b+t->b;continue;}
			int zs=x1->b+t->b;
			while(now->next!=NULL&&now->next->b>zs)now=now->next;
			if(now->next==NULL)
			{
				now->next=newnode();
				now->next->a=x1->a*t->a;
				now->next->b=zs;continue;
			}
			if(now->next->b<zs)
			{
				NODE *tmp=newnode();
				tmp->a=x1->a*t->a;tmp->b=zs;
				tmp->next=now->next;
				now->next=tmp;continue;
			}
			if(now->next->b==zs){now->next->a+=x1->a*t->a;continue;}
		}
	
	NODE *now=ans;
	while(now!=NULL)
	{
		if(now->a!=0)printf("%lld %lld ",now->a,now->b);
		now=now->next;
	}
}	
void read(NODE* x,char *s1)
{
	int i=0;NODE *now=x;
	while(s1[i]!='\0')
	{
		int f=1,s=0,a,b;
		while(s1[i]<'0'||s1[i]>'9'){if(s1[i]=='-')f=-1;i++;}
		while(s1[i]>='0'&&s1[i]<='9'){s=s*10+s1[i]-'0';i++;}
		a=s*f;	f=1,s=0;
		while(s1[i]<'0'||s1[i]>'9'){if(s1[i]=='-')f=-1;i++;}
		while(s1[i]>='0'&&s1[i]<='9'){s=s*10+s1[i]-'0';i++;}
		b=s*f;
		now->a=a;now->b=b;
		now->next=newnode();
		now=now->next;now->a=0;
	}
}
