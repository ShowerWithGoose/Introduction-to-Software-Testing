#include<stdio.h>
#include<stdlib.h>
struct poly{
	int co;
	int exp;
	struct poly *next;
}*head1,*head2,*head_ans,*p1,*p2,*pa;
//int a[10000][2];
void input(struct poly *p);
int compare(const void *p1,const void *p2);
int main()
{
	int t=1;
	head1=(struct poly*)malloc(sizeof(struct poly));
	head2=(struct poly*)malloc(sizeof(struct poly));
	p1=head1;
	p2=head2;
	input(p1);
	input(p2);
	head_ans=(struct poly*)malloc(sizeof(struct poly));
	pa=head_ans;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			if(p1->next==NULL&&p2->next==NULL)
			{
				pa->next=NULL;
			}
			else{
				pa->next=(struct poly*)malloc(sizeof(struct poly));
			}
			pa->co=(p1->co)*(p2->co);
			pa->exp=(p1->exp)+(p2->exp);
			p2=p2->next;
			t++;
			pa=pa->next;
		}
		p2=head2;
		p1=p1->next;
	}
	pa=head_ans;
	int i=0,j,cot,k,a[1000][2];
	while(pa!=NULL)
	{
		a[i][0]=pa->co;
		a[i][1]=pa->exp;
		pa=pa->next;
		i++;
	}
	qsort(a,i-1,2*sizeof(int),compare);
	for(j=1;j<i;j++)
	{
		if(a[j][1]==a[j-1][1])
		{
			cot=a[j-1][0]+a[j][0];
			a[j][0]=0;
			k=j+1;
			while(a[k][1]==a[j][1])
			{
				cot+=a[k][0];
				a[k][0]=0;
				k++;
			}
			a[j-1][0]=cot;
			j=k;
		}
	}
	printf("%d %d",a[0][0],a[0][1]);
	for(j=1;j<i;j++)
	{
		if(a[j][0]!=0)
			printf(" %d %d",a[j][0],a[j][1]);
	}
	return 0;
}
void input(struct poly *p)
{
	char c;
	scanf("%d%d",&p->co,&p->exp);
	while(1)
	{
		c=getchar();
		if(c!=' ')
			break;
		p->next=(struct poly*)malloc(sizeof(struct poly));
		p=p->next;
		scanf("%d%d",&p->co,&p->exp);
	}
	p->next=NULL;
	return;
}
int compare(const void *q1,const void *q2)
{
	if(*((int *)q1+1)>*((int *)q2+1))
		return -1;
	if(*((int *)q1+1)<*((int *)q2+1))
		return 1;
	return 0;
}

