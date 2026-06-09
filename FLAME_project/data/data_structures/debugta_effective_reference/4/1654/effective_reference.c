#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char s[100005],t[1005];
typedef struct node{
	char word[10005]; 
	int num;
}LLN;
LLN x[10005];
int count=0;
int search(LLN *list,char *w);
int insert(LLN *list,int pos,char *w); 
int main()
{
	int i=0,j,k,n;
	char c;
	FILE *in;
	in=fopen("article.txt","r");
	c=fgetc(in);
	while(c!=EOF)//∂¡»Î 
	{
		s[i++]=c;
		c=fgetc(in);
	}
	for(i=0;i<strlen(s);i++)
	{
		memset(t,0,sizeof(t));
		if(isalpha(s[i]))
		{
			for(j=i;j<strlen(s);j++)
			{
				if(isalpha(s[j]))
					s[j]=tolower(s[j]);
				else
					break;
			}
			for(k=0;k<j-i;k++)
				t[k]=s[i+k];
			t[k]='\0';
			n=search(x,t);
			i=j;
		}
		else continue;
	}
	for(i=0;i<count;i++)
	{
		printf("%s %d\n",x[i].word,x[i].num);
	}
	fclose(in);
	return 0;
}
int search(LLN *list,char *w)
{
	int low=0,high=count-1,mid=0;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(w,list[mid].word)<0)
			high=mid-1;
		else if(strcmp(w,list[mid].word)>0)
			low=mid+1;
		else
		{
			list[mid].num++;
			return 0;
		}
	}
	return insert(list,low,w);
}
int insert(LLN *list,int pos,char *w)
{
	int i;
	for(i=count-1;i>=pos;i--)
		list[i+1]=list[i];
	strcpy(list[pos].word,w);
	list[pos].num=1;
	count++;
	return 1;
}

