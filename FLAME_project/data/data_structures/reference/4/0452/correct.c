#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct vocab{
	char word[30];
	int num;
}vocab[1050];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char s[1010],temp[30];
	int i=0,j=0,k=0,len1,len2,len3,t;
	
	while(fgets(s,1010,in)!=NULL)
	{
		len1=strlen(s);
		for(k=0;k<len1;k++)
		{
			if((s[k]>=65&&s[k]<=90)||(s[k]>=97&&s[k]<=122))
			{
				vocab[i].word[j]=tolower(s[k]);
				j++;
			}
			else
			{
				vocab[i].word[j]='\0';
				j=0;
				i++;
			}
		}
	}
	len2=i;
	for(i=0;i<len2;i++)
	{   
		for(j=i+1;j<len2;j++)
		{
			if(strcmp(vocab[i].word,vocab[j].word)>0)
			{
				strcpy(temp,vocab[i].word);
				strcpy(vocab[i].word,vocab[j].word);
				strcpy(vocab[j].word,temp);
			}
		}
	}
	for(i=0;i<len2;i++)
	{   t=0;
	    vocab[i].num=1;
		for(j=i+1;j<len2;j++)
		{
			if(strcmp(vocab[i].word,vocab[j].word)==0)
			{
				vocab[i].num+=1;
				vocab[j].word[0]='\0';
				t=1;
			}
		    if(vocab[j].word[0]=='\0')
		    {
			continue;
		    }
		    else 
			{
		        if(t==1)
		        {
				i=j-1;
			    }
			    break;
			}
		}
	}
	for(i=0;i<len2;i++)
	{
		if(vocab[i].word[0]!='\0')
		{
			printf("%s %d\n",vocab[i].word,vocab[i].num);
		}
	}
	fclose(in);
	return 0;
}

