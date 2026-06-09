#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxline 1024
char a[maxline],word[1000][30];
int cnt[1000],i=0,len=0,j=0,q=0,k=1,wordcnt=0,flag[1000]={0},mai=0;
int main() 
{
	FILE* in = fopen("article.txt","r");
	if(NULL==in) 
	{
		printf("Failed to open the file !\n");
		return 0;
	}
	while(fgets(a,maxline-1,in)!=NULL) 
	{
		for(i=0; i<strlen(a); i++) 
		{
			len=0;
			while(isalpha(a[i])!=0) {
				if(a[i]-'A'>=0&&a[i]-'Z'<=0) 
				{
					a[i]=tolower(a[i]);
				}
				word[j][len]=a[i];
				len++;
				i++;
				q=1;
			}
			if(q==1) 
			{
				j++;
				q=0;
			}
		}
	}
	wordcnt=j;
	k=1;
	for(i=0; k; i++) 
	{
		k=0;
		for(j=0; j<wordcnt; j++) 
		{
			char str1[30]= {'\0'};
			if(strcmp(word[j+1],word[j])<0) 
			{
				strcpy(str1,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],str1);
				k=1;
			}
		}
	}

	for(i=0; i<=wordcnt; i++)
		cnt[i]=1;
	mai=1;
	for(i=2; i<=wordcnt; i++) 
	{
		if(strcmp(word[mai],word[i])==0) 
		{
			flag[i]=1;
			cnt[mai]+=1;
		} else 
		{
			mai=i;
		}
	}
	for(i=1; i<=wordcnt; i++) 
	{
		if(flag[i]==0)
			printf("%s %d",word[i],cnt[i]);
		if(i<wordcnt&&flag[i]==0)
			printf("\n");
	}
}

