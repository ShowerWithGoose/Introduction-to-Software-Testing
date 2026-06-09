#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct word{
	char ch[100];
	int num;
}words[10000];
int cmp(const void*a,const void*b)
{
	struct word*c=(struct word*)a;
	struct word*d=(struct word*)b;
	return strcmp(c->ch,d->ch);
}
int main()
{   int u=0,o=0,j=0,i=0,flag[10000]={0},k=0,p=0,flag1[1000]={0};
   char s[2000]={0};
	FILE *in;
	in=fopen("article.txt","r");
	if(in==NULL)printf("shit");
	while(fgets(s,1024,in)!=NULL) 
	{  
	    for(i=0;i<1000;i++)
	    {
		 flag1[i]=0;}
	    int len=strlen(s);
		o=0;
	    for(i=0;i<len;i++)
	    {
	    	if(!isalpha(s[i]))
	    	{
			flag1[o]=i; 
			o++;
		}		
		}
		j=0;
			if(o==0)
		{
			for(j=0;j<len;j++)
			{if(isupper(s[j]))
				{  
					s[j]+='a'-'A';
				}
		   words[u].ch[k]=s[j];
		   k++;
	      	words[u].num=1;
		}}
		else{
		
		for(p=0;p<o;p++)
		{
		for(;j<flag1[p];j++)
		{
				if(isupper(s[j]))
				{  
					s[j]+='a'-'A';
				}
		   words[u].ch[k]=s[j];
		   k++;
	      	words[u].num=1;
		}
		j=flag1[p]+1;k=0;u++;
		}
				
			
		
		for(j=flag1[o-1]+1;j<len;j++)
		{if(isupper(s[j]))
				{  
					s[j]+='a'-'A';
				}
		   words[u].ch[k]=s[j];
		   k++;
	      	words[u].num=1;
		}u++;k=0;
		}		
}
	qsort(words,u,sizeof(words[0]),cmp);
	
	for(j=1;j<u;j++)
	{
		if(strcmp(words[j].ch,words[j-1].ch)==0)
		{
			flag[j-1]=1;
			words[j].num+=words[j-1].num;
		}
	}
	for(j=0;j<u;j++)
	{  if(flag[j]==0&&words[j].ch[0]!='\0')
		{
		printf("%s %d\n",words[j].ch,words[j].num);
    	}
	}
	fclose(in);
	return 0;
 } 

