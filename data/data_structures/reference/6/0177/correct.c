#include <stdio.h>
#include <stdlib.h>

int st[110],p,op,x;

int main()
{
	while(1)
	{
		scanf("%d",&op);
		if(op==-1) break;
		if(op==1)
		{
			scanf("%d",&x);
			if(p>=100) printf("error ");
			else st[++p]=x;
		}
		else if(p) printf("%d ",st[p--]);
		else printf("error ");
	}
	return 0;
}

