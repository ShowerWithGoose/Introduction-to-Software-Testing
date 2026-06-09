#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct word{
	char w[1000];
	int time;
}words[100000];
int getword();
void search();
FILE *in;
char s[1000];
int first,last,len;
int main()
{
	int i;
	in=fopen("article.txt","r");
	//printf("%d",in);
	while(getword()!=-1)
	{
		//printf("%s\n",s);
		search();
	}
	//printf("%d",len);
	for(i=0;i<len;i++)
	{
		printf("%s %d\n",words[i].w,words[i].time);
	}
	fclose(in);
	return 0;
}
int getword()
{
	memset(s,0,sizeof(s));
	char c;
	int i=0;
	while(1)
	{
		c=fgetc(in);
		if(isalpha(c))
		{
			s[i]=tolower(c);
			i++;
			while(1)
			{
				c=fgetc(in);
				if(isalpha(c))
				{
					s[i]=tolower(c);
					i++;
				}
				else{
					s[i]='\0';
					return 0;
				}
			}
		}
		else if(c==EOF)
		{
			return -1;
		}
	}
}
void search()
{
	int flag=0,i,j,mid;
	if(len==0)
	{
		strcpy(words[0].w,s);
		words[0].time=1;
		len++;
		return;
	}
	last=len;
	first=0;
	while(first<last)
	{
		mid=(first+last)/2;
		if(strcmp(s,words[mid].w)<0)
		{
			last=mid;
		}
		else if(strcmp(s,words[mid].w)>0)
		{
			first=mid+1;
		}
		else{
			flag=1;
			words[mid].time++;
			break;
		}
	}
	if(flag==0)
	{
		i=first;
		for(j=len-1;j>=i;j--)
		{
			strcpy(words[j+1].w,words[j].w);
			memset(words[j].w,0,sizeof(words[j].w));
			words[j+1].time=words[j].time;
		}
		strcpy(words[i].w,s);
		words[i].time=1;
		len++;
	}
	return;
}

