#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000][100];
struct letter
{
	char a[100];
	int count;	
};
struct letter word[1000]; 
int compare(struct letter *p1,struct letter *p2)
{
	if(strcmp(p1->a,p2->a)>0) return 1;
	if(strcmp(p1->a,p2->a)<0) return -1;
}
int main()
{
	int i,j;
	int mark=0;
	int count1=0,count2=0;
	char c;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			if(mark==1)
			{
				count1++;
				count2=0;
				mark=0;
			}
			c='a'-'A'+c;
			s[count1][count2]=c;
			count2++;
		}
		else if(c>='a'&&c<='z')
		{
			if(mark==1)
			{
				count1++;
				count2=0;
				mark=0;
			}
			s[count1][count2]=c;
			count2++;
		}
		else 
		{
			mark=1;
		}
	}
	int k=0;
	for(i=0;i<=count1;i++)
	{
		int flag=0;
		for(j=0;j<k;j++)
		{
			if(strcmp(s[i],word[j].a)==0)
			{
				flag=1;
				word[j].count++;
			} 
		}
		if(flag==0&&s[i][0]!='\0') 
		{
			word[k].count=0;
			strcpy(word[k++].a,s[i]);
		}
	}
	qsort(word,k,sizeof(word[0]),compare);
	for(i=0;i<k;i++)
	{
		printf("%s %d\n",word[i].a,word[i].count+1);
	}
	return 0;
 } 

