#include <stdio.h> 
#include <stdlib.h>
struct expression{
	int coef;
	int pow;
};
typedef struct expression exp;
exp a[10000],b[10000],c[10000];
int cmp(const void *p1, const void *p2);
int main(void)
{
	int k=0;
	char ch;
	int n1=0, n2=0;//n1是第一个多项式的项数,n2是第二个多项式的项数 
	do
	{
		scanf("%d%d%c",&a[n1].coef,&a[n1].pow,&ch);
		n1++;
	}while(ch!='\n');
	
	do
	{
		scanf("%d%d%c",&b[n2].coef,&b[n2].pow,&ch);
		n2++;
	}while(ch!='\n');
	
	qsort(a,n1,sizeof(exp),cmp);
	qsort(b,n2,sizeof(exp),cmp);
	
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			c[k].coef=a[i].coef*b[j].coef;
			c[k].pow=a[i].pow+b[j].pow;
			k++;
		}	
	}
	qsort(c,k,sizeof(exp),cmp);	
	for(int i=0;i<k;i++)
	{
		if(c[i].pow==c[i+1].pow&&c[i].pow!=0)
		{
			c[i+1].coef+=c[i].coef;
			c[i].coef=0;	
		}	
	} 
	qsort(c,k,sizeof(exp),cmp);
	for(int i=0;i<k;i++)
	{
		if(c[i].coef!=0)
		{
			printf("%d %d ",c[i].coef,c[i].pow);	
		}	
	}
	return 0;
}
int cmp(const void *p1, const void *p2)
{
	struct expression *a = (struct expression *)p1;
	struct expression *b = (struct expression *)p2;
	return b->pow-a->pow; //降序 若为升序则是a->pow-b->pow 
}

