#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int in[110];
int main()
{
	int op,a;
	scanf("%d",&op);
	for(;;)
	{
		if(op == -1) break;
		if(op == 1)
		{
			scanf("%d",&a);
			if(in[0] < 100) in[++in[0]] = a;
			else printf("error ");
		}
		else
		{
			if(in[0]) printf("%d ",in[in[0]--]);
			else printf("error ");
		}
		scanf("%d",&op);
	}
	return 0;
}

