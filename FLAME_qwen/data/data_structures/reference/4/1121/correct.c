#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct l
{
	char word[200];
	int cnt;
}list[1000];

int cmp(const void *p1,const void *p2)
{
	struct l *a=(struct l *)p1,*b=(struct l *)p2;
	if(strcmp(a->word,b->word)<0)
	return -1;
	if(strcmp(a->word,b->word)>0)
	return 1;
}

int main()
{
	int i,j,k,ans1=0,ans2,flag,len;
	char s1,s2[1000][50];
	FILE *in;
	in=fopen("article.txt","r");
	i=0;j=0;
	while(fscanf(in,"%c",&s1)!=EOF)
	{
		if(isalpha(s1))
		{
			s2[i][j++]=tolower(s1);
		}
		else
		{
			s2[i][j]='\0';
			i++;
			j=0;
		}
	}
	s2[i][j]='\0';
	ans2=i;
	for(i=0;i<=ans2;i++)
	{
		if(s2[i][0]=='\0')
		continue;
		else
		{
			flag=0;
			for(j=0;j<ans1;j++)
			{
				if(strcmp(list[j].word,s2[i])==0)
				{
					list[j].cnt++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				strcpy(list[ans1].word,s2[i]);
				list[ans1].cnt++;
				ans1++;
			}
		}
	}
	qsort(list,ans1,sizeof(list[0]),cmp);
	for(i=0;i<ans1;i++)
	printf("%s %d\n",list[i].word,list[i].cnt);
	fclose(in);
	return 0;
} 

