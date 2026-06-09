#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1024][1024];
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	char ch;
	ch=getc(fp);
	int i=0,h=0;
	int j=0,k;
	int count[1000];
	while(ch!=EOF)	
	{
		if(ch>='A'&&ch<='Z')
		{
			ch+=32;
			s[i][j]=ch;
			j+=1;
		}
		else if(ch>='a'&&ch<='z')
		{
			s[i][j]=ch;
			j+=1;
		}
		else
		{
			s[i][j]='\0';
			j=0;
			i+=1;
		}
		ch=fgetc(fp);
	}
	int sum=i;
	for(j=0;j<sum;j++)
	    count[j]=1;
	for(j=0;j<sum;j++)
	{
		for(k=j+1;k<sum;k++)
		{
			if(strcmp(s[j],s[k])>0)
			{
				char y[100];
				strcpy(y,s[j]);
				strcpy(s[j],s[k]);
				strcpy(s[k],y);
			}
		}
	}
	for(j=0;j<sum;j++)
	{
		for(k=j+1;k<sum;k++)
		{
			int x=0;
			if(!strcmp(s[j],s[k]))
			{
				count[j]+=1;
				s[k][0]='\0';
				x=2;
			}
			if(s[k][0]=='\0')
			continue;
			else
			{
				if(x==2)
				j=k-1;
				break;
			}
		}
	}
	for(i=0;i<sum;i++)
	{
		if(s[i][0]!='\0')
			printf("%s %d\n",s[i],count[i]);	

	}
	
	fclose(fp);
	return 0;
}



