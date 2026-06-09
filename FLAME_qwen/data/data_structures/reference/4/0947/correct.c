#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char word1[1005][105],word2[1005][105];
int comp(const void* p1,const void* p2);
int main()
{
	char c;
	int i=0,j=0,flag,n,t,k=0;
//	int flag1 = 0;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		if(c>='a'&&c<='z')
		{
			word1[i][j]=c;
			j++;
		}
		if(c>='A'&&c<='Z')
		{
			word1[i][j]=c+'a'-'A';
			j++;
		}
		if(c<'A'||(c>'Z'&&c<'a')||c>'z')
		{
//			printf("%d %s\n",i, word1[i]);
			i++;
			word1[i][0]='0';
			j=0;
		}	
	}
	for(t=0;t<i;t++)
		{
			if(word1[t][0]!='0')
			{
				strcpy(word2[k],word1[t]);
				k++;
			}
		}
	n=k;
//	printf("%d\n",n);
	qsort(word2,n,sizeof(word2[0]),comp);
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=i+1;j<n+1;j++)
		{
			if(word2[i][0]!=0&&strcmp(word2[i],word2[j])!=0)
			{
				printf("%s",word2[i]);
				printf(" %d\n",flag+1);
				break;
			}
			if(strcmp(word2[i],word2[j])==0)
			{
				flag++;
				continue;
			}
		}
		i+=flag;	
	}
	fclose(in);
	return 0;
}
int comp(const void* p1,const void* p2)
{
	if(strcmp((char *)p1, (char *)p2)<0)
		return -1;
	return 1;
}
