#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int sort(const void* a,const void* b);
struct word {
    char s[1024];
    int num;

}p[2048];        
  
int main()
{
	int i;
	FILE* fp=fopen("article.txt","r");
	char str[15000],c;
	int sum=0;
	 while ((c = fgetc(fp)) != EOF)
	 {

	  	    str[sum++] = c;  
    }
    
    sum=0;
    int k=0;
    int t=strlen(str);
    for (i = 0; i < strlen(str); i++)
    {
if(isalpha(str[i])) 
	p[sum].s[k++]=tolower(str[i]);
    	else
    	{
    		sum++;
    		k=0;
		}
	
	}
	
	qsort(p,sum,sizeof(p[0]),sort);
	for (i = 0; i < sum; i++)
	{
		if(strlen(p[i].s))
		 p[i].num = 1;
	}
        
	for(i=0;i<sum;i++)
	{
		if(!strcmp(p[i].s,p[i+1].s))
		{
		p[i+1].num+=p[i].num;
		p[i].num=0;	
		}
	}
		for(i=0;i<sum;i++)
		{
			if(p[i].num!=0)
			printf("%s %d\n",p[i].s,p[i].num);
		}
		return 0;
		fclose(fp);
	}
    

int sort(const void* a,const void* b)
{
	struct word* c=(struct word*)a;
	struct word* d=(struct word*)b;
    return strcmp(c->s, d->s); 
}





