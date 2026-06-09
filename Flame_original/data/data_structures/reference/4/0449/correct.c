#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char word[1000][20];
char txt[10000];
int count[1000];
char tmpword[20];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0,k=0,n=0;
	char ch;
	while((ch=fgetc(in))!=EOF)
	{
		txt[i++]=ch;
	}
	int cnt=0;
	int flag=0;
	for(j=0;j<i;j++)
	{
		k=0;
		memset(tmpword,0,sizeof(tmpword));
		while(('a'<=txt[j]&&'z'>=txt[j])||('a'<=tolower(txt[j])&&'z'>=tolower(txt[j])))
		{
			tmpword[k]=tolower(txt[j]);
			k++;
			j++;
		}
		flag=0;
		for(n=0;n<cnt;n++)
		{
			if(strcmp(word[n],tmpword)==0)
			{
				flag=1;
				count[n]++;
			}
		}
		if(flag==0&&strlen(tmpword)>0)
		{
			strcpy(word[cnt],tmpword);
			cnt++;
		}
	}
	int tmp=0;
	for(i=0;i<cnt-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(word[j],word[j+1])>0)
			{
				memset(tmpword,0,sizeof(tmpword));
				strcpy(tmpword,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],tmpword);
				tmp=count[j];
				count[j]=count[j+1];
				count[j+1]=tmp;
			}
		}
	}
	for(i=0;i<cnt;i++)
	{
		printf("%s %d\n",word[i],count[i]+1);	
	}
	fclose(in);
	return 0;
}



