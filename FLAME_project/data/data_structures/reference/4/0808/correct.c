#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1024
typedef struct Key
{
	char word[30];
	int count;
}key;
int cmp(const void *a, const void *b)
{
	return strcmp((*(key*)a).word,(*(key*)b).word);
}
int main()
{
	int i,j=0,k,flag=0,pt=0,q;
	char word2[30],wj[max];
	key p[500];
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(wj,max-1,in)!=NULL)
	{
		for(i=0;wj[i]!='\0';i++)
		{
			memset(word2,0,sizeof(word2));
			k=0;
			if((wj[i]>='a'&&wj[i]<='z')||(wj[i]>='A'&&wj[i]<='Z'))
			{
				for(j=i;j<=strlen(wj);j++)
				{
					if((wj[j]>='a'&&wj[j]<='z')||(wj[j]>='A'&&wj[j]<='Z'))
					{
						word2[k]=tolower(wj[j]);
						k++;
					}
					else
					{
						flag=0;
						word2[k]='\0';
						for(q=0;q<pt;q++)
						{
							if(strcmp(word2,p[q].word)==0)
							{
								flag=1;
								p[q].count++;
								break;
							}
						}
						if(flag==0)
						{
						    strcpy(p[pt].word,word2);
						    pt++;
						}
						i=i+k;
						break;
					}
				}
			}
		}
	}
	qsort(p,pt,sizeof(p[0]),cmp);
	for(i=0;i<pt;i++)
	{
		printf("%s",p[i].word);
		printf(" %d\n",p[i].count+1);
	}
}


