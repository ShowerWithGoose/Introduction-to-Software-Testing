#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1024
typedef struct node
{
	char line[20];
	int count;
}total;
int cmp(const void *a,const void *b)
{
	total *str1=(struct node*)a;
	total *str2=(struct node*)b;
	if(strcmp(str1->line,str2->line)>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
total f[100];
char c;
int i;
int main()
{
    int j, g,flag;
    FILE *in;
    in =  fopen("article.txt","r");
    while(fscanf(in,"%c",&c)!=EOF)
   {
       if(isalpha(c))
        { f[i].line[j]=c;
        j++;
        flag=1;}
        else{
        	if(!isalpha(f[i].line[0]))
        	{continue;
			}
			else if(flag==1)
			{f[i].line[j]='\0';
			f[i].count=1;
			i++;
			j=0;
			}
		}
	}

	int k=i;
	for(i=0;i<k;i++)
	{
		for(j=0;j<strlen(f[i].line);j++)
		{	if(isupper(f[i].line[j]))
		{	f[i].line[j]=tolower(f[i].line[j]);
			}
		}
}
			qsort(f,k,sizeof(struct node),cmp);
			for(i=0;i<k;)
	{
		if(strcmp(f[i].line,f[i+1].line)==0)
		{
			for(j=i;j<k-1;j++)
			{
				f[j+1]=f[j+2]; 
			}
			f[i].count++;
			k--;
		}
		else 
		{
			i++;
		}}
	
	for(i=0;i<k;i++)
	{
		if(f[i].line[0]!='\0')
		{
			printf("%s %d\n",f[i].line,f[i].count);
		}
		
	}
	
	return 0;
}	 
		

