#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
FILE *in;
typedef struct{
	int num;
	char a[50];
}list;
void cap(char *);
int Is_word(char);
int cmp(const void*,const void*);
int main()
{
	int i=0,j,k=0,n,key;
	char trial;
	list word[1000];
	for(i=0;i<1000;i++)word[i].num=0;
	char tmp[50];
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&trial)!=EOF)
	{
		if(Is_word(trial)<0)continue;
		else
		{
			tmp[0]=trial;
			i=1;
			while(fscanf(in,"%c",&tmp[i])!=EOF)
			{
				if(Is_word(tmp[i])>0)i++;
				else
				{
					tmp[i]='\0';
					break;
				}
			}
			key=0;
			n=strlen(tmp);
			cap(tmp);
			for(j=0;j<k;j++)
			{
				if(strcmp(tmp,word[j].a)==0)
				{
					word[j].num++;
					key=1;
					break;
				}
			}
			if(key==0)
				strcpy(word[k++].a,tmp);
			}
	}
	qsort(word,k,sizeof(word[1]),cmp);
	for(i=0;i<k;i++)printf("%s %d\n",word[i].a,word[i].num+1);	
	return 0;
}
void cap(char *a)
{
	int n=strlen(a);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		if(a[i]>=65&&a[i]<=90)
		{
			a[i]=a[i]+'a'-'A';
		}
	}
}
int Is_word(char x)
{
	if('A'<=x&&x<='Z')return 1;
	if('a'<=x&&x<='z')return 1;
	return -1;
}
int cmp(const void*p1,const void*p2)
{
	list *q1=(list *)p1;
	list *q2=(list *)p2;
	if(strcmp(q1->a,q2->a)>0)return 1;
	return -1;
}



