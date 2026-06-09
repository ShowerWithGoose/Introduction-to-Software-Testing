#include<stdio.h>
#include<string.h>

int shu[10000];
char hao[10000];
int tops,toph=-1;

int main()
{
	int i=0,len,sum=0;
	char c;
	scanf("%d",&shu[0]);
	while(1)
	{
		scanf("%c",&c);
		while(c==' ')scanf("%c",&c);
		if(c!='=')
			hao[++toph]=c;
		if(c=='='&&toph==-1)break;
		scanf("%d",&shu[++tops]);
		if(hao[toph]=='*')
		{
			toph--;
			tops--;
			shu[tops]=shu[tops]*shu[tops+1];
		}
		else if(hao[toph]=='/')
		{
			toph--;
			tops--;
			shu[tops]=shu[tops]/shu[tops+1];
		}	
		else if((hao[toph]=='+'||hao[toph]=='-')&&toph>=1)
		{
			if(hao[toph-1]=='+')
			{
				shu[tops-2]=shu[tops-2]+shu[tops-1];
				shu[tops-1]=shu[tops];
				tops--;
				toph--;
				hao[toph]=hao[toph+1];
			}
			else if(hao[toph-1]=='-')
			{
				shu[tops-2]=shu[tops-2]-shu[tops-1];
				shu[tops-1]=shu[tops];
				tops--;
				toph--;
				hao[toph]=hao[toph+1];
			}
		}
		if(c=='=')break;
	}
	if(toph>=0&&hao[toph]=='-')
		printf("%d",shu[0]-shu[1]);
	else if(toph>=0&&hao[toph]=='+')
		printf("%d",shu[0]+shu[1]);
	else printf("%d",shu[0]);
	return 0;
}

