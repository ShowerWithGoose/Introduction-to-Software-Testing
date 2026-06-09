#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct word
{
	char w[100];
	int num;
}words[1000000];
int total;
int cmp(const void *a,const void*b);
int search(char a[]);
int insert(char b[]);
 int main()
 {
	FILE *in;
	int len,flag,len1;
	int i=0,j=0,k=0;
	char line[1024],hold[50];
	in=fopen("article.txt","r");
	if(in==NULL)
	return -1;
	while(fgets(line,1024,in)!=NULL)
	{
		len=strlen(line);
		for(i=0;i<len;i++)
		{
			if(isalpha(line[i])!=0)
			{
				while(line[i]!=' '&&(isalpha(line[i])!=0))
				{
						hold[j]=tolower(line[i]);
						i++;j++;
				}
				hold[j]='\0';
				flag=search(hold);
				if(flag!=-1)
				words[flag].num++;
				else
				insert(hold);
				len1=strlen(hold);
				for(k=0;k<len1;k++)
				hold[k]='\0';
				j=0;
			}
		}
	}//实现单词的读入 
	qsort(words,total,sizeof(words[0]),cmp);
	for(k=0;k<total;k++)
	{
		printf("%s %d\n",words[k].w,words[k].num);
	 } 
	return 0;
 }
 int cmp(const void *a,const void *b)
 {
 	return strcmp(((struct word*)a)->w,((struct word*)b)->w);
 }
 int search(char a[])
 {
 	int i=0;
 	for(i=0;i<total;i++)
 	{
 		if(strcmp(a,words[i].w)==0)
 		return i;
	 }
	 return -1;
 }
 int insert(char b[])
 {
 	strcpy(words[total].w,b);
 	words[total].num++;
 	total++;
 	return total;
 }
 
 

