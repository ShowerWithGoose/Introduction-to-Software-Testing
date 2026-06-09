#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	char name[50];
	int count;
} word;
int getword(FILE *IN,char *p)
{
	char c;
	while(!isalpha(c=fgetc(IN)))
	{
		if(c==EOF)
		{
			return c;
		}
		else
		{
			continue;
		} 
	}
	do{
		*p=tolower(c);
		p++;
	}while(isalpha(c=fgetc(IN)));
	*p='\0';
	return 1;
 } 
 int cmp(const void *p1,const void *p2)
 {
 	word *p11,*p22;
 	p11 = (word*)p1;
 	p22 = (word*)p2;
 	return strcmp(p11->name,p22->name);
 }
int main()
{
	FILE *IN;
	IN = fopen("article.txt","r");
	char tep[50];
	int num_of_word=0,flag,i;
	word List[10000];
	for(i=0;i<10000;i++)
	{
		List[i].count=0;
	}
	while(getword(IN,tep)!=EOF)
	{
		for(i=0,flag=0;i<num_of_word;i++)
		{
			if(strcmp(tep,List[i].name)==0)
			{
				flag = 1;
				List[i].count++;
				break;
			}
		}
		if(flag)
		continue;
		strcpy(List[num_of_word].name,tep);
		List[num_of_word].count++;
		num_of_word++;
	}
	qsort(List,num_of_word,sizeof(word),cmp);
	for(i=0;i<num_of_word;i++)
	printf("%s %d\n",List[i].name,List[i].count);
	fclose(IN);
	return 0; 
}

