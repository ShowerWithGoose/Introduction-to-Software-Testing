#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char c,s[100],a[100][100],temp[100],num[100],b[100][100];
	int i,j=0,l=0,k=0,p=0,len,len2;
	FILE *fp;
	fp= fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF) s[p++] = c;         
    s[p] = '\0';

	len=strlen(s);
						
	for(i=0;i<len-1;i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
		a[l][j]=s[i];
		j++;
		}
		else
		{
		l++;
		j=0;
		}			 //每行是一个单词 
	}
	for(i=0;i<l;i++)
	{
		len2=strlen(a[i]);
		for(j=0;j<len2;j++)
		{
		a[i][j]=tolower(a[i][j]);
		}
	}						//大写变小写 
	for(i=0;i<l;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}						//排成字典序 
	
	for(i=0;i<100;i++)
	num[i]=1;
	for(i=0;i<l;i++)
	{
		
		if(strcmp(a[i],a[i+1])!=0)
		{
			strcpy(b[k],a[i]);
			k++;
		}
		else
			num[k]++;
	}						//如果每行不同将该行给另个数组b,相同则次数加1 
	for(i=1;i<k;i++)
	{
		
		printf("%s %d\n",b[i],num[i]);
	}
	fclose(fp); 
	return 0;
}



