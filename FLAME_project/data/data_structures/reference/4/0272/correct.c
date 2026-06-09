#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int n=0;
typedef struct wordlist{
	int num;
	char con[100];
}word,*pword;
word wd[10010];
int Cmp(const void *pa, const void *pb)
{
pword a = (pword)pa;
pword b = (pword)pb;
if (strcmp(a->con,b->con)>0)
{
return 1;
}
else 
{
return -1;
}
}
int getword(FILE *fp, char *w)
{
int c;
while(!isalpha(c=fgetc(fp))) 
if(c == EOF) return c; 
else continue;
do {
*w++ = tolower(c);
} while(isalpha(c=fgetc(fp))); 
*w='\0';
return 1;
}
int main()
{
	int i,rep;
	FILE *fp;
	fp=fopen("article.txt","r");
    char tmp[100],*ptmp=tmp;
    while(getword(fp,ptmp)!=EOF)
    {
    	rep=0;
    	for(i=0;i<n;i++)
    	{
    		if(strcmp(wd[i].con,tmp)==0)
    		{
    			rep=1;
    			break;
			}
		}
		if(rep==0)
		{
			strcpy(wd[n].con,tmp);
			wd[n].num=1;
			n++;
		}
		else
		{
			wd[i].num++;
		}
	}
	qsort(wd,n,sizeof(word),Cmp);
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",wd[i].con,wd[i].num);
	}
	fclose(fp);
	return 0;
}

