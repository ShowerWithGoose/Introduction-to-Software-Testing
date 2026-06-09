#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 105
int stack[maxn];
int pt=0;
int main()
{
	int p,x;
	while(1)
	{
		scanf("%d",&p);
		if(p==-1)break;
		if(p==1)
		{
			scanf("%d",&x);
			stack[++pt]=x;
		}
		else
		{
			if(!pt){printf("error ");}
			else
			{
				printf("%d ",stack[pt]);
				pt--;
			}
		}
	}
	return 0;
}



