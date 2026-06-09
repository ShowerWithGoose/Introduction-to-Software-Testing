#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<math.h> 
struct cole
{
	char word[1000];
	int count;
	struct cole *link;
};
struct cole *Word=NULL;
int get(FILE *inm,char *po)
{
	int c;
	while(!isalpha(c=fgetc(inm)))
		if(c==EOF)
			return c;
		else 
			continue;
	do
	{
		*po++=tolower(c);
	}
	while(isalpha(c=fgetc(inm)));
	*po='\0';
	return 1;
}
int insert(struct cole *pole,char *fade)
{
	struct cole *com;
	com=(struct cole *)malloc(sizeof(struct cole));
	if(com==NULL)
		return -1;
	strcpy(com->word,fade);
	com->count=1;
	com->link=NULL;
	if(Word==NULL)
		Word=com;
	else if(pole==NULL)
	{
		com->link=Word;
		Word=com;
	}
	else 
	{
		com->link=pole->link;
		pole->link=com;
	}
	return 0;
}
int search(char *der)
{
	struct cole *goat,*ger=NULL;
	for(goat=Word;goat!=NULL;ger=goat,goat=goat->link)
	{
		if(strcmp(der,goat->word)<0)
			break;
		else if(strcmp(der,goat->word)==0)
		{
			goat->count++;
			return 0;
		}
	}
	return insert(ger,der);
}
int main()
{
	char word[1000];
	FILE *in;
	in=fopen("article.txt","r");
	struct cole *core;
	while(get(in,word)!=EOF)
	{
		if(search(word)==-1)
		{
			fprintf(stderr,"Memory");
			return -1;
	    }
	}
	for(core=Word;core!=NULL;core=core->link)
	{
		printf("%s %d\n",core->word,core->count);
    }
	return 0;
}




