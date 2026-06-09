#include<stdio.h>
int z[100];
int top=-1;
void jinzhan(int);
void chuzhan();
int main()
{
	int cz,sj;
	while(1)
	{
		scanf("%d",&cz);
		if(cz==0)
		{

			chuzhan();
		}
		if(cz==1)
		{
			scanf("%d",&sj) ;
			jinzhan(sj);
		}
		if(cz==-1)
		break;
	}
	return 0;
}
void jinzhan(int i)
{
	if(top==99)
	printf("error ");
	else
	{
		z[top+1]=i;
		top++;
	}
}
void chuzhan()
{
	if(top==-1)
	printf("error ");
	else
	{
		printf("%d ",z[top]);
		z[top]=0;
		top--;
	}
}



