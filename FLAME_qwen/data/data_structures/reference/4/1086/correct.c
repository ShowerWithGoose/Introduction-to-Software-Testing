#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	char word[50];
};
void del(struct node article[],struct node info[],int a,int flag[])
{
	int m,n,p,q,r;
	for(m=0,r=0;m<a;m++)
	{
		for(n=0,p=0,q=0;n<strlen(article[m].word);n++)
		{
			if(isalpha(article[m].word[n]))
			{
				info[r].word[p]=tolower(article[m].word[n]);
				p++;
				q=1;
			}
			else if(isalpha(article[m].word[n])==0&&q==1)
			{
				flag[r]++;
				r++;
				p=0;
				q=0;
			}
		}
		if(q==1)
		{
			flag[r]++;
			r++;
			p=0;
		}
	}
}
char line;	
int main()
{
	int temp;
	int i,j,k,l,m;
	int a=0;
	int flag[500]={0};
	FILE *in, *out;
	in=fopen("article.txt","r");
	out=fopen("output.txt","w");
	struct node article[1000],info[1000];
	struct node tmp; 
	while(fscanf(in,"%s",article[a].word)!=EOF)
	{
		a++;
	}
	
	del(article,info,a,flag);
//	printf("%d\n",a); 
//	for(k=0;k<a;k++)
//	{
//		printf("%s %d\n",info[k].word,flag[k]);
//	}
	
	
//	for(i=0;strcmp(info[i].word,"\0")!=0;i++) printf("%s %d\n",info[i].word,flag[i]);
	
	for(k=0;info[k].word[0] != '\0';k++)
	{
//		if(info[k].word[0] == 'w')
//	for(int kk=0;info[kk].word[0]!=0;kk++)
//	{
//		printf("current:\n%s %d\n",info[kk].word,flag[kk]);
//	}
//	printf("-----------\n");
		for(l=k+1;strcmp(info[l].word,"\0")!=0;l++)
		{
//		printf("---k(%d):%s\n----l(%d):%s\n",k,info[k].word,l,info[l].word);
			if(strcmp(info[k].word,info[l].word)>0)
			{
				tmp=info[k];
				info[k]=info[l];
				info[l]=tmp;
				temp=flag[k];
				flag[k]=flag[l];
				flag[l]=temp;
			}
			else if(strcmp(info[k].word,info[l].word)==0)
			{
				flag[k]+=flag[l];
				for(m=l;strcmp(info[m+1].word,"\0")!=0;m++)
				{
					flag[m]=flag[m+1];
					info[m]=info[m+1];
				}
				strcpy(info[m].word,"\0");
				l--;
			} 
		}
	}
	for(i=0;strcmp(info[i].word,"\0")!=0;i++) printf("%s %d\n",info[i].word,flag[i]);
	fclose(in);
	fclose(out);
	return 0; 
} 

