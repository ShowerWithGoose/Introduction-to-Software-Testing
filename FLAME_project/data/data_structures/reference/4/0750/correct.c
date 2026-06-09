#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
char temp[1010];

struct ListNode
{
	char word[210];
	int num;
};
struct ListNode node[1010];
int l=0,index[1010];//单词的个数 

int cmp(const void *pa,const void *pb)
{
	int a=*((int *)pa);
	int b=*((int *)pb);
	return strcmp(node[a].word,node[b].word);	
}

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int len,i,j,k,flag,val,p;
	while(fgets(temp,1000,in)!=NULL)
	{
		len=strlen(temp);
		for(i=0;i<len;i++)
		{
			if(temp[i]>='A'&&temp[i]<='Z') temp[i]=temp[i]-'A'+'a';
		}
		for(i=0;i<len;i++)
		{
			if(temp[i]>='a'&&temp[i]<='z')
			{
				flag=0;
				for(j=i+1;j<len;j++)
				{
					if(temp[j]<'a'||temp[j]>'z')
					{
						k=j;
						break;
					}
					if(j==len-1)
					{
						k=len;
						break;
					}
				}
				for(j=0;j<l;j++)
				{
					if(k-i==strlen(node[j].word))
					{
						for(p=0;p<k-i;p++)
						{
							if(node[j].word[p]==temp[p+i]) flag++;
							else break;
						}
					}
					if(flag==k-i) 
					{
						val=j;
						break;
					}
				}
				if(flag==k-i) node[val].num++;
				else
				{
					for(j=0;j<k-i;j++) node[l].word[j]=temp[j+i];
					node[l].num++;
					l++;
				}
				i=k; 
			}
		}
		memset(temp,'\0',sizeof(temp)-1);
	}
	for(i=0;i<l;i++) index[i]=i;
	//for(i=0;i<l;i++) printf("%s %d\n",node[i].word,node[i].num);
	qsort(index,l,sizeof(int),cmp);
	for(i=0;i<l;i++) printf("%s %d\n",node[index[i]].word,node[index[i]].num);
	return 0;	
}

