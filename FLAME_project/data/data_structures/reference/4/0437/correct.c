#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct stu{
	char word[100];
	int t;
};

FILE *in;
struct stu list[1000],k;
char v[1000];
int i,j,n,m;

void del(int z)
{
	for(int q=0;z+q+1<n;q++)
	{
		list[z+q]=list[z+q+1];
	}
	n--;
}

int main()
{
	FILE *in,*out;
	in=fopen("article.txt","r");
	while(fgets(v,1000,in)!=NULL)
	{
		for(i=0;i<strlen(v);i++)
	    {
		    if(v[i]>='A'&&v[i]<='Z')
		    {
			    v[i]=v[i]+'a'-'A';
		    }
	    }
	    for(i=0;i<strlen(v);i++)
	    {
		    if(v[i]>='a'&&v[i]<='z')
		    {
			    for(j=0;;j++)
			    {
				    if(v[i+j]>='a'&&v[i+j]<='z')
				    {
					    list[n].word[j]=v[i+j];
				    }
				    else
				    {
					    n++;
					    i=i+j;
					    break;
				    }
			    }
		    }
	    }
	}
	m=n;
	for(i=0;i<n;i++)
	{
		for(j=1;j+i<n;j++)
		{
			if(strcmp(list[i].word,list[i+j].word)==0)
			{
				list[i].t++;
				del(i+j);
				j--;
			}
		}
	}
	for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i-1;j++)
    	{
    		if(strcmp(list[j].word,list[j+1].word)>0)
    		{
    			k=list[j];
    			list[j]=list[j+1];
    			list[j+1]=k;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",list[i].word,list[i].t+1);
	}
}

