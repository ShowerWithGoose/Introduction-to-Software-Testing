#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807£¨>10^18£©   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

struct Voc
{
	char word[500];
	int flag;
}voc[590];
char s[300],temp[300];
int cmp(const void* e1, const void* e2)
{
	return strcmp(((struct Voc*)e1)->word,((struct Voc*)e2)->word); 
}


int main()
{
	int j,len,num,k;
	memset(voc,0,sizeof(voc));
	memset(s,0,sizeof(s));
	memset(temp,0,sizeof(temp));
	freopen("article.txt", "r+", stdin); 
	num=0;
	for(int i=0;i<590;i++)
	{
		voc[i].flag=1;
	}
	while(gets(s)!=NULL)
	{
		len=strlen(s);
		j=0;
		for(int i=0;i<=strlen(s);i++)
		{
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					s[i]=s[i]^32;
				}
				temp[j]=s[i];
				j+=1;
			}
			else
			{
				for(k=0;k<num;k++)
				{
					if(strcmp(voc[k].word,temp)==0)
					{
						voc[k].flag+=1;
						break;
					}
				}
				if(k==num)
				{
					strcpy(voc[k].word,temp);
					num+=1;
				}
				memset(temp,0,sizeof(temp));
				j=0;
			}
		}
		
	}
	qsort(voc,num,sizeof(voc[1]),cmp);
	for(int i=0;i<num;i++)
	{
		if(voc[i].word[0]!=0)
		{
			printf("%s %d\n",voc[i].word,voc[i].flag);
		}
		
	}
 } 

