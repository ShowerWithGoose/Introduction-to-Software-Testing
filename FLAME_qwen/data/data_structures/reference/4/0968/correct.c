#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int n=0; 
struct Word{
	char name[100];
	int time;
}word[200];
void   _Tolower(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
	if(s[i]<='Z'&&s[i]>='A')
	{
		s[i]-='A';
		s[i]+='a';
	}
	i++;
	}
}
void search_same(struct Word word[],char *s)
{
	int i=0;
	for(i=0;word[i].name[0]!='\0';i++)
	{
		if(strcmp(word[i].name,s)==0)
		{
			word[i].time++; return;
		}
	}
	if(s[0]!='\0')
	{
	strcpy(word[i].name,s);n++;	
	}
}
void direct(struct Word word[])
{
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1-i;j++)
	if(strcmp(word[j].name,word[j+1].name)>0) 
	{
		char buf[100];int mid;
		strcpy(buf,word[j].name);
		strcpy(word[j].name,word[j+1].name);
		strcpy(word[j+1].name,buf);
		mid=word[j].time;
		word[j].time=word[j+1].time;
		word[j+1].time=mid;
	}
}
void clear(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
	if(s[i]>'z'||s[i]<'a') s[i]='^';
	}
}
int main()
{
	FILE *in,*out;
	in=fopen("article.txt","r");
	char buf[100];
	int i;
	for(i=0;i<2;i++)
	{
		word[i].name[0]='\0';
		word[i].time=0;
	}
	while(fscanf(in,"%s",buf)!=EOF)
	{
		_Tolower(buf);
		clear(buf);
		for(i=0;buf[i]!='\0';)
		{
			char _buf[100];
			int j;
			for(j=i;buf[j]!='^'&&buf[j]!='\0';j++)
			{
				_buf[j-i]=buf[j];
			}
			_buf[j-i]='\0';
			search_same(word,_buf);
			if(buf[j]=='\0')
			break;
			else
			i=j+1;
		}
		
	}
	direct(word);
	for(i=0;word[i+1].name[0]!='\0';i++)
	{
		printf("%s %d\n",word[i].name,word[i].time+1);
	}
		printf("%s %d",word[i].name,word[i].time+1);
	fclose(in);
	return 0; 
} 

