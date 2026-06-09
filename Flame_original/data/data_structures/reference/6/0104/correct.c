#include<stdio.h>

int st[10005],h=0,opt;

int main()
{
	while(1)
	{
		scanf("%d",&opt);
		if(opt==-1) break;
		if(opt==0)
		{
			if(!h) printf("error ");else printf("%d ",st[h--]);
		}else scanf("%d",&st[++h]);
	}
	return 0;
}

