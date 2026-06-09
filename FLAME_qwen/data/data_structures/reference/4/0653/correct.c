#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main ()
{
	struct{
		char chara[1005];
		int time;
	}word[1005];
	FILE*in=fopen("article.txt","r");
	char read[10005],c;
	int k=0,i,j;
	while((c=fgetc(in))!=EOF)
	{
		read[k]=c;
		k++;
	}
	k=0;
	int order=0;
	for(i=0;i<strlen(read);i++)
	{
		if(isalpha(read[i])==0)
		{
			k++;
			order=0;
		}
		else 
		{
			if(read[i]>=65&&read[i]<=90)word[k].chara[order++]=read[i]+32;
			else word[k].chara[order++]=read[i];
		}
	}
	char temp[1005];
	for(i=0;i<k;i++)
	{
		int f=1;
		for(j=0;j<k-i;j++)
		{
			if(strcmp(word[j].chara,word[j+1].chara)>0)
			{
			    strcpy(temp,word[j].chara);
			    strcpy(word[j].chara,word[j+1].chara);
			    strcpy(word[j+1].chara,temp);
	   		    f=0;
	   	    }
		}
		if(f==1)break;
	}
	for(i=0;i<=k;i++)
	
		if(strlen(word[i].chara)>0)word[i].time=1;
	
	for(i=0;i<k;i++)
	{
		if(!strcmp(word[i].chara,word[i+1].chara))
		{
		   word[i+1].time+=word[i].time;
		   word[i].time=0;
	    }
	}
	for(i=0;i<=k;i++)
	{
		if(word[i].time!=0)
		{
		    printf("%s %d\n",word[i].chara,word[i].time);
	    }
	}
	return 0;
 } 

