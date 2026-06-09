#include<stdio.h>
#include<string.h>
#include<ctype.h>
char word[100][20],ch[1000];
int num[100];
int main()
{
	FILE *in; 
	in=fopen("article.txt","r");
	int i=0;
	char c; 
	while ((c=fgetc(in))!=EOF)
	{ 
		if('a'<=c&&c<='z'||'A'<=c&&c<='Z')
		ch[i]=tolower(c);
		i++;
		//printf("%c",c);
	}
	int a=0,b=0;
	for(int j=0;j<i;j++)
	{
		if('a'<=ch[j]&&ch[j]<='z')
		{
			while('a'<=ch[j]&&ch[j]<='z')
			{
				word[a][b]=ch[j];
				j++;
				b++;
			}
			word[a][b]='\0';
			a++;
			b=0;
		}
	}
	
	char word1[100];
	for(int i=0;i<a;i++)
	{
		for(int j=i+1;j<a;j++)
		{
			if(strcmp(word[i],word[j])>0)
			{
				strcpy(word1,word[i]);
		        strcpy(word[i],word[j]);
		        strcpy(word[j],word1);
			}	
		}
	}
	for(int i=0;i<a;i++)
	{
		num[i]=1;
		for(int j=i+1;j<a;j++)
		{
			if(strcmp(word[i],word[j])==0)
			{
				num[i]++;
				word[j][1]='1';
			}
		}
	}
	for(int i=0;i<a;i++)
	{
		if(word[i][1]!='1')
		{
			printf("%s %d\n",word[i],num[i]);
		}
	}
	fclose(in);
	return 0;
}



