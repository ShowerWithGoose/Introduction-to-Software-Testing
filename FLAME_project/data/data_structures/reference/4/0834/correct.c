#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb);
struct words{
	char word[30];
	int num;
};
struct words wordlist[1000];
void search(char a[],int i);
int k;
int main()
{
	int i=0,j;
	char temp[30]={"\0"},tmp;
	FILE *op;
	op=fopen("article.txt","r");
	while((tmp=fgetc(op))!=EOF)
	{
		int ok=0;
		for(j=0;j<i;j++)
		temp[j]='\0';
		i=0;
		while((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z'))
		{
			ok=1;
	    	if(tmp>='A'&&tmp<='Z')
	    	tmp+='a'-'A';
			temp[i]=tmp;
			i++;
			tmp=fgetc(op);
		}
		if(ok==1)
		search(temp,i);
	}
	qsort(wordlist,k,sizeof(wordlist[0]),cmp);
	for(i=0;i<k;i++)
	printf("%s %d\n",wordlist[i].word,wordlist[i].num);
	fclose(op);
	return 0;
}
void search(char a[],int i)
{
	int j,ok=0;
	for(j=0;j<k;j++){
		if(strcmp(wordlist[j].word,a)==0){
			ok=1;
			wordlist[j].num++;
		}	
	}
	if(ok==0){
		strcpy(wordlist[k].word,a);
		wordlist[k].num=1;
		k++;
	}
}
int cmp(const void *pa,const void *pb)
{
	struct words a=*((struct words *)pa);
	struct words b=*((struct words *)pb);
	return strcmp(a.word,b.word);
}

