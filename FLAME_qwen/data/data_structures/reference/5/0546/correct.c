#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 

struct node
{
	long long a;
	long long b;
	int flag;
};
int main()
{
	struct node f1[1000],f2[1000],f3[3000],f4[3000];
	char s;
	int i=0;
	for(i=0;;i++)
	{
		scanf("%lld%lld%c",&f1[i].a,&f1[i].b,&s);
		if(s=='\n')
		break;	
	}	
	int l1=i;
	for(i=0;;i++)
	{
		scanf("%lld%lld%c",&f2[i].a,&f2[i].b,&s);
		if(s=='\n')
		break;	
	}	
	int l2=i;
//	printf("%d %d",l1,l2);
	int k=0; 
	for(i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			f3[k].a=f1[i].a*f2[j].a;
			f3[k].b=f1[i].b+f2[j].b;
			f3[k].flag=1;
			k++;
		}
	}
//	printf("%d",k);
	int jj=0;
	for(i=0;i<k;i++)
	{
		if(f3[i].flag==0)
		continue;
		else if(f3[i].flag==1)
		{
//			printf("1\n");
			f4[jj].a=f3[i].a;
			f4[jj].b=f3[i].b;
//			printf("%lld",f4[jj].b)
			jj++;
		}
		for(int j=i+1;j<k;j++)
		{
			if(f3[j].flag==0)
			continue;
			if(f3[j].b==f4[jj-1].b&&f3[j].flag==1)
			{
				f4[jj-1].a=f4[jj-1].a+f3[j].a;
				f3[j].flag=0;
//				printf("%lld %lld\n",f3[j].b,f4[jj-1].b);
			}
		}
	}
	struct node temp;
	for(i=0;i<jj;i++)
	for(int j=i;j<jj;j++)
	{
		if(f4[i].b<f4[j].b)
		{
			temp=f4[i];
			f4[i]=f4[j];
			f4[j]=temp;
		}
	}
	for(i=0;i<jj;i++)
	if(f4[i].a!=0)
	printf("%lld %lld ",f4[i].a,f4[i].b);
}

