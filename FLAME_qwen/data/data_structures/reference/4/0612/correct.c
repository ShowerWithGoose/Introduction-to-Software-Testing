#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct h{
	char word[1000];
	int times;
};
typedef struct h hh;
char s[1000],c[1000];
int i=0,j,k,ch,flag=0,p=0;
int cmp(const void*p1,const void*p2);
hh a[1000];
int main()
{
	FILE *fp1 = fopen("article.txt","r");
	ch=fgetc(fp1);
	while(ch!=EOF)
	{
		if(ch>='A'&&ch<='Z')
		{
		   s[i]=ch-'A'+'a';
	    }
	    else s[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
    for(i=0;i<strlen(s);i++)
    {
    	if(s[i]>='a'&&s[i]<='z')
    	{
    	   for(j=i;j<strlen(s);j++)
    	   {
    	   	    if(s[j]<'a'||s[j]>'z')
    	   	    {
    	   		    break;
			    }
		   }
			memset(c,0,sizeof(c));
		    for(k=0;k<j-i;k++)
			{
				c[k]=s[i+k];  
		    }
		    strcpy(a[p].word,c);
		    p++;
		    i=j;
		}
	}
	qsort(a,p,sizeof(hh),cmp);
	for(i=0;i<p;i++) 
	{
	    a[i].times=1; 
    }
    
	for(i=0;i<p;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0) 
		{
			a[i+1].times+=a[i].times; 
			a[i].times=0;
		}
	}
	qsort(a,p,sizeof(hh),cmp);
	for(i=0;i<p;i++)
	{
		if(a[i].times!=0)
		{
            printf("%s %d\n",a[i].word,a[i].times);
		}

	}
}  
int cmp(const void*p1,const void*p2) 
{
	struct h *a=(struct h*)p1;
	struct h *b=(struct h*)p2;
	return strcmp(a->word,b->word);
}

