#include <stdio.h>
#include <string.h>
int main()
{
	char nu[105]="";
	scanf("%s",nu);
	int mi,i,j,posd,l,l1,l2,pos1,pos2;
	l=strlen(nu);
	for(i=1;i<=l;i++)
	{
		if(nu[i-1]>'0'&&nu[i-1]<='9')
			pos2=i;
		
		if(nu[i-1]=='.')
			posd=i;
	}
	for(i=l;i>=1;i--)
	{
		if(nu[i-1]>'0'&&nu[i-1]<='9')
			pos1=i;
	}
	if(nu[0]=='-')
		printf("-");
	if(pos1==pos2)
	{
		printf("%ce%d",nu[pos1-1],pos1<posd?posd-pos1-1:posd-pos1);
	}
	else
	{
		
		for(i=pos1;i<=pos2;i++)
		{
			
			if(i!=posd)
				printf("%c",nu[i-1]);
				
			if(i==pos1)
				printf(".");
		}
		printf("e%d",pos1<posd?posd-pos1-1:posd-pos1);
		
	}
	return 0;
}

