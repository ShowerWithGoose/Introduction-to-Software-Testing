#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct inode
{
	char word[64];
	int count;
};
struct inode list[10007];
int n;
int getword(FILE *fp,char *w)
{
	int t;
	while(!isalpha(t=fgetc(fp)))
	{
		if(t==EOF)
		{
			return t;
		} 
	}
	do{
		*w++=tolower(t);
	}while(isalpha(t=fgetc(fp)));
	*w='\0';
	return 1;
}
void insert(int pos,char *w)
{
	int i;
	for(i=n-1;i>=pos;i--)
	{
		list[i+1]=list[i];
	}
	strcpy(list[pos].word,w);
	list[pos].count=1;
	n++;
	return ;
}
int search(int low,int high,char *w)
{
	int mid=(low+high)/2;
	if(low>high)
	{
		insert(low,w);
		return -1;
	}
	if(strcmp(w,list[mid].word)>0)
	{
		return search(mid+1,high,w);
	}
	if(strcmp(w,list[mid].word)<0)
	{
		return search(low,mid-1,w);
	}
	return mid;
}
int main()
{
	FILE *p;
	p=fopen("article.txt","r");
	char inword[107];
	while(getword(p,inword)!=EOF)
	{
		int u=search(0,n-1,inword);
		if(u!=-1)
		{
			list[u].count++;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%s %d\n",list[i].word,list[i].count);
	}
	return 0;
}

