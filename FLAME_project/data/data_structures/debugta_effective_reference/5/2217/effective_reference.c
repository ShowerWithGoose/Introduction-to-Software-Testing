#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct node
{
	long long k;
	long long n;
}x[10000],y[10000],ans[100000];
int cmp(const void *a, const void *b);
int main()
{
	int i=0,j=0,num=0,b,flag=0;
	char p[10000],q[10000];
	gets(p);
	gets(q);
	for(i=0;i<strlen(p);i++)
	{
		if(p[i]=='-') flag=1;
		else if(p[i]>='0'&&p[i]<='9')num=num*10+p[i]-'0';
		else if((p[i]==' ')&&j%2==0&&flag==1)
		{
			x[j/2].k=-num;
			num=0;
			j++;
			flag=0;
		}
		else if((p[i]==' '||p[i]=='\n')&&j%2==0&&flag==0)
		{
			x[j/2].k=num;
			num=0;
			j++;
			flag=0;
		}
		else if((p[i]==' '||p[i]=='\n')&&j%2==1)
		{
			x[j/2].n=num;
			num=0;
			j++;
		}
		x[j/2].n=num;
	}
	/*for(i=0;i<j;i=i+2)
	{
		printf("%d %d ",x[i/2].k,x[i/2].n);
	}
	printf("\n\n");*/
	int k=0,l=0;
	num=0;
	for(i=0;i<strlen(q);i++)
	{
		if(q[i]=='-') flag=1;
		else if(q[i]>='0'&&q[i]<='9')num=num*10+q[i]-'0';
		else if((q[i]==' '||q[i]=='\n')&&k%2==0&&flag==1)
		{
			y[k/2].k=-num;
			num=0;
			k++;
			flag=0;
		}
		else if((q[i]==' '||q[i]=='\n')&&k%2==0&&flag==0)
		{
			y[k/2].k=num;
			num=0;
			k++;
			flag=0;
		}
		else if((q[i]==' '||q[i]=='\n')&&k%2==1)
		{
			y[k/2].n=num;
			num=0;
			k++;
		}
		y[k/2].n=num;
	}
	/*for(i=0;i<k;i=i+2)
	{
		printf("%d %d ",y[i/2].k,y[i/2].n);
	}
	printf("\n\n");*/
	for(i=0;i<j/2+1;i++)
	{
		for(b=0;b<k/2+1;b++)
		{
			ans[l].k=x[i].k*y[b].k;
			ans[l++].n=x[i].n+y[b].n;
		}
	}
	qsort(ans,l,sizeof(ans[0]),cmp);
	for(i=0;i<l-1;i++)
	{
		if(ans[i].n==ans[i+1].n)
		{
			ans[i+1].k=ans[i].k+ans[i+1].k;
			ans[i].k=0;
		}
	}
	for(i=0;i<l;i++)
	{
		if(ans[i].k!=0)
		printf("%d %d ",ans[i].k,ans[i].n);
	}
	return 0;
}
int cmp(const void *a, const void *b) 
{
	struct node s1=*(struct node*)a;
	struct node s2=*(struct node*)b; 
	return (s2.n-s1.n); 
}

