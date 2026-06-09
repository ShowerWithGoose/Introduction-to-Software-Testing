#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char w[120];
	int t;
}word[10000];
int cmp(const void *a, const void *b);
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	if (fp == NULL) {
		perror("Can't open filein_txt");
		return 1;
	}
	char l[1024];
	int i=0,j=0,k=0;//i:num of letters,j:num of words,k for letter
	while(fgets(l,1024,fp)!=NULL)
	{
		for(i=0;i<strlen(l);i++)
		{
			if((l[i]<65)||(l[i]>=91&&l[i]<=96)||l[i]>=123)
			{
				k=0;
				j++;
				word[j-1].t=1;				
				word[j].t=1;
			}
			if(l[i]>='A'&&l[i]<='Z') l[i]=l[i]+32;
			if(l[i]>='a'&&l[i]<='z')			
				word[j].w[k++]=l[i];			
		}
		memset(l,'\0',sizeof(l));
	}
	/*printf("j=%d\n",j);
	for(i=0;i<=j;i++)
	{
		printf("%s %d\n",word[i].w,word[i].t);
	}
	printf("\n\n");*/
	qsort(word,j+1,sizeof(word[0]),cmp);
	/*for(i=0;i<=j;i++)
	{
		printf("%s %d\n",word[i].w,word[i].t);
	}
	printf("\n\n");*/
	for(i=0;i<=j-1;i++)
	{
		if(strcmp(word[i].w,word[i+1].w)==0)
		{
			word[i].w[0]='0';
			word[i+1].t=word[i].t+word[i+1].t;
		}
	}
	for(i=0;i<=j;i++)
	{
		if(word[i].w[0]>='a'&&word[i].w[0]<='z')
		printf("%s %d\n",word[i].w,word[i].t);
	}
	fclose(fp);
	return 0;
} 
int cmp(const void *a, const void *b) 
{
	struct node s1=*(struct node*)a;
	struct node s2=*(struct node*)b; 
	return strcmp(s1.w,s2.w); 
}

