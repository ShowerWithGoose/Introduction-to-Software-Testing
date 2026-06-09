#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define lower(c) (c>='A'&&c<='Z')?(c-'A'+'a'):c
int num=0;
struct word{
	char s1[100];
	int freq;
};
struct word dictionary[10000];
void search(struct word dictionary[],char s[])
{
	int i;
	int flag=0;
	for(i=0;i<num;i++)
	{
		if(strcmp(s,dictionary[i].s1)==0)
		{
			dictionary[i].freq++;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(dictionary[num].s1,s);
		dictionary[num].freq=1;
		num++;
	}
}
void change(char s[])
{
	int i,j,k;
	char s1[50];
	int l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(isalpha(s[i])==0)
		{
			while(isalpha(s[++i])==0);
		}
		k=0;
			for(j=i;j<l&&isalpha(s[j])!=0;j++)
			{
				s1[k++]=lower(s[j]);
			}
			i=i+k;
			if(k!=0)
			{
				s1[k]='\0';
				search(dictionary,s1);
			}
	}
	
}
int cmp(const void *p1,const void *p2)
{
	struct word *a=(struct word *)p1;
	struct word *b=(struct word *)p2;
	if(strcmp(a->s1,b->s1)<0)return -1;
	else return 1;
}
int main()
{
	
	char s[100];
	FILE *in=fopen("article.txt","r");
	while(fscanf(in,"%s",s)>0)
	{
		change(s);
	}
	fclose(in);
	qsort(dictionary,num,sizeof(struct word),cmp);	
	int i;
	for(i=0;i<num;i++)
	{
		printf("%s %d\n",dictionary[i].s1,dictionary[i].freq);
		
	}
	return 0;
	
}

