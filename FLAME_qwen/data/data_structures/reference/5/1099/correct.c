#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAX 3000

int cmp(const void*q1,const void*q2);

struct node{
	long p;
	long c;
}m1[MAX],m2[MAX],m[MAX];
typedef struct node Node;

int main()
{
int cnt=0,cnt1=0,cnt2=0,i,j; 
char ch;
do   
	{
		scanf("%ld%ld",&m1[cnt1].c,&m1[cnt1].p);
		cnt1++;
	}while((ch=getchar())!='\n');
	qsort(m1,cnt1,sizeof(Node),cmp);
do   
	{
		scanf("%ld%ld",&m2[cnt2].c,&m2[cnt2].p);
		cnt2++;
	}while((ch=getchar())!='\n');
	qsort(m2,cnt2,sizeof(Node),cmp);
	
for(i=0;i<cnt1;i++)
{
	for(j=0;j<cnt2;j++)
	{
		m[cnt].c=m1[i].c*m2[j].c;
		m[cnt].p=m1[i].p+m2[j].p;
		cnt++;
	}
}
qsort(m,cnt,sizeof(Node),cmp);

	for(i=0;i<cnt;i++)
	{
		if((m[i].p==m[i+1].p)&&m[i].p!=0)
		{
			m[i+1].c+=m[i].c;
			m[i].c=0;
		}
	}
qsort(m,cnt,sizeof(Node),cmp);

for(i=0;i<cnt;i++)
	{
		if((m[i].c)!=0)
		{
			printf("%ld %ld ",m[i].c,m[i].p);
		}
	}

return 0;
}
int cmp(const void*q1,const void*q2)
{
	struct node *a=(struct node*)q1;
	struct node *b=(struct node*)q2;
		if(b->p==a->p) return 0;
		else if(b->p > a->p)return 1;
		else return -1;
}

