#include <stdio.h>
int main()
{
	int flag;
	int a[1000],b[1000],t=0,s=1;
	while(1)
	{
		scanf("%d",&flag);
		if(flag==1&&t<=100)
		{
			t++;
			scanf("%d",&a[t]);
		}
		else if(flag==1&&t>100)
		{
			b[s]=-1;
			s++;
		}
		else if(flag==0&&t!=0)
		{
			b[s]=a[t];
			a[t]=0;
			t--;
			s++;
		}
		else if(flag==0&&t==0)
		{
			b[s]=-1;
			s++;
		}
		else if(flag==-1)
		{
			break;
		}
	}
	for(int i=1;i<s;i++)
	{
		if(b[i]!=-1)
		{
			printf("%d ",b[i]);
		}
		else if(b[i]==-1)
		{
			printf("error ");
		}
	}
	return 0;
}

