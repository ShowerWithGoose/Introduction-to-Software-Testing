#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define bufsiz 32

int getword(FILE*fp,char*w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
		if(c==EOF)
			return c;
		else continue;
	do
		*w++=tolower(c);
	while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}

typedef struct data
{
	char word[bufsiz];
	int times;
}data;
int num=0;
data list[512];

void search(char*newword)
{
	int i,flag=0;
	for(i=0;i<num;i++)
	{
		if(strcmp(list[i].word,newword)>0)
		{
			insert(newword,i);
			flag=1;
			break;
		}else if(strcmp(list[i].word,newword)==0)
		{
			list[i].times++;
			flag=1;
			break;
		}			
	}
	if(flag==0)
		insert(newword,num);
}

void insert(char*newword,int position)
{
	int j;
	for(j=num-1;j>=position;j--)
		list[j+1]=list[j];
	strcpy(list[position].word,newword);
	list[position].times=1;
	num++;
}

int main()
{
	FILE *fp_in;
	char word[bufsiz];
	int i; 
	//fp_in=("C:\Users\lenovo\Desktop\article.txt","r");
	//fp_in=("C:\\Users\\lenovo\\Desktop\\article.txt","r");
	if((fp_in=fopen("article.txt","r"))==NULL)
	{
		perror("Sorry!\n");
		return -1;
	}
	while(getword(fp_in,word)!=EOF)
		search(word); 
	for(i=0;i<num;i++)
		printf("%s %d\n",list[i].word,list[i].times);	
	fclose(fp_in);	
	return 0;
}

