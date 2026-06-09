#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Node
{
	char word[20];
	int num;
	int val;
}st[100];
char s[1000];
int main()
{
	char ch;
	FILE *fp=fopen("article.txt","r");
	int i=0,j,k=0,q=0;
	while((ch=fgetc(fp))!=EOF){s[i++]=ch;}
	s[i]='\0';
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(isalpha(s[i]))
		{
			for(q=0;isalpha(s[i])>0;i++,q++)
			{
				st[k].word[q]=(tolower(s[i]));
			}
			st[k].word[q]='\0';st[k].num++;st[k].val=1;k++;
		}
	}
	int N=k-1;
	int l,tp;
	int fg = 1;
    for(l = 0; fg; l++) 
	    {
		    fg = 0;
		    char temp1[25];
		    for(j = N; j >= l+1; j--) 
		    {
                if(strcmp(st[j-1].word,st[j].word)>0)
                {
                    strcpy(temp1,st[j].word);
                    strcpy(st[j].word,st[j-1].word);
                    strcpy(st[j-1].word,temp1);
                    tp=st[j].num;st[j].num=st[j-1].num;st[j-1].num=tp;
                    fg = 1;
                }
	        }
	    }
	for(i=0;i<=N;i++)
	{
		if(st[i].val==0)
		{
			continue;
		}
		for(j=0;j<=N;j++)
	    {
	    	if(i==j)continue;
	    	if(st[j].val==0)
		    {
			    continue;
		    }
	    	if(strcmp(st[i].word,st[j].word)==0)
	    	{
	    		st[i].num+=st[j].num;
	    		st[j].val=0;
			}
		}
	}
	
	for(i=0;i<=N;i++)
	{
		if(st[i].val==0)
		{
		    continue;
		}
		else printf("%s %d\n",st[i].word,st[i].num);
	}
	fclose(fp);
	return 0;
} 

