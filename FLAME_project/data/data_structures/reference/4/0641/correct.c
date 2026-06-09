#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag2[80];
typedef struct{
	char words[80];
	int num;
}Word;
Word a[80];
int cmp(const void *a,const void *b){
	Word*c=(Word*)a;
	Word*d=(Word*)b;
	return strcmp(c->words,d->words);
	}
int ischar(char ch){
	if(ch>='a'&&ch<='z')
	return 1;
	else if(ch>='A'&&ch<='Z')
	return 1;
	else
	return 0;
}
char tolower(char c){
	if(c>='A'&&c<='Z')
	return c+32;
	return c;
}

int main()
{
	FILE*in=fopen("article.txt","r");
	int j,flag=0,index=0,i=0;
	char ch,word[80]={0};
	while((ch=getc(in))!=EOF){
		if(ischar(ch))
		{
		word[index++]=tolower(ch);
		flag=1;
		}
		else
		{
			if(flag==1){
				strcpy(a[i].words ,word);
				a[i++].num =1;
				flag=0;
				memset(word,0,sizeof(word));
				index=0;
			}
			
		}
	}
	int count=i;
	qsort(a,count,sizeof(Word),cmp);
	for(i=0;i<count-1;i++)
	for(j=i+1;j<count;j++){
		if(flag2[j]==1)
		continue;
		if(strcmp(a[j].words ,a[i].words )==0){
			flag2[i]=2;
			flag2[j]=1;
			a[i].num ++;
		}
	}
	
	for(i=0;i<count;i++)
	{
		if(flag2[i]==1)
		continue;
		printf("%s %d\n",a[i].words ,a[i].num );
	}
	return 0;
	fclose(in);
	}




