#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char dc[99][20];
int count[99];
char zs[20]; 
int flag=1;
int main()
{
	char zf;
	char zs[20];
	int i=0,j=0,n,m;
	FILE*op;
	op=fopen("article.txt","r")	;
	zf=fgetc(op);
	while(zf!=EOF)
	{
		if(zf>='A'&&zf<='Z')
		{
			dc[i][j]=zf+32;
			j++;
		}
		else if(zf>='a'&&zf<='z')
		{
			dc[i][j]=zf;
			j++;
		}
		else 
		{
			dc[i][j]='\0';
			j=0;
			i++;
		}
		zf=fgetc(op);	
	}
	m=i;
	for(i=0;i<m;i++)
	{
		for(n=0;n<m;n++)
		{
			for(j=n+1;j<m;j++)
			{
				if(strcmp(dc[n],dc[j])>0)
				{
					strcpy(zs,dc[j]);
					strcpy(dc[j],dc[n]);
					strcpy(dc[n],zs);
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		count[i]++;
		flag=1;
		for(j=i+1;j<m;j++)
		{
			if(!strcmp(dc[i],dc[j]))
			{
			  count[i]++;
			  dc[j][0]='\0';
			  flag=0;
			}
			if(dc[j][0]!='\0')
			{
				if(flag==0)
				{
					i=j-1;
				}
				break;
			}
			else
			{
				continue;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(dc[i][0]!='\0')
		{
			printf("%s %d\n",dc[i],count[i]);
		}
	}
}

