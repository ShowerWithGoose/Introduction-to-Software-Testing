#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1024
struct node
{
	char word[100];
	int count;
};

char lower(char c)
{
	if(c>='A'&&c<='Z')
		return 'a'-'A'+c;
	return c;
} //תСд 

void sort(struct node array[],int n)
{
    int i,j;
    struct node tmp;
    for(i=0;i<n-1;++i)
        {
        	for(j=0;j<n-i-1;++j)
		  {
            if(strcmp(array[j].word,array[j+1].word)>0)
			{
              tmp=array[j];
	          array[j]=array[j+1];
              array[j+1]=tmp;
            }
           }
		}
}

int main()
{
	char s[MAXLINE];
	int i,j,k=0;
	int p=0,flag=0,num=0;
	struct node page[500];
	FILE *in,*out;
	if((in=fopen("article.txt","r"))==NULL)
	{
	  printf("Can't open this file;");
	  return 1;
	}
	in=fopen("article.txt","r");
    while(fgets(s,MAXLINE-1,in)!=NULL)
    {
    	for(i=0;i<strlen(s);i++)
    	{
    		s[i]=lower(s[i]);
		}
    	for (i=0;i<strlen(s);i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                page[p].word[k++]=s[i];
                flag=1;
            }
            else if(flag!= 0)
            {
                page[p].word[k]='\0';
                page[p].count=1;
                p++;
                k=0;
				flag=0;
            }
        }
	}
	for(i=0;i<p;i++)
	{
		for(j=i+1;j<p;j++)
		{
			if(strcmp(page[i].word,page[j].word)==0)
			{
				page[i].count++;
				memset(page[j].word,'\0',sizeof(page[j].word));
			}
		}
	}
	sort(page,p);
	for(i=0;i<p;i++)
	{
		if(strlen(page[i].word)>0)
		printf("%s %d\n",page[i].word,page[i].count);
    }
	return 0;
}

