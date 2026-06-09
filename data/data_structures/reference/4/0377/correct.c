#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct colet{
	char word[100];
	int cont;
}coll[5000];

int cmp(const void *a,const void *b)
{
	int ans=strcmp((*(struct colet*)a).word,(*(struct colet*)b).word);
	return ans;
}
int read(int i,int k,char w[])
{
	int t=0,f=0,sum=i;
	char s[100]={0};
	for(;k<strlen(w);k++)
	{
		if((w[k]>='a' && w[k]<='z') || (w[k]>='A' && w[k]<='Z'))
		{
			s[t]=tolower(w[k]);
			t++;
			f=1;
		}
		else if(f==1){
			sum=read(sum+1,k+1,w);
		}
	}
	strcpy(coll[i].word,s);
	memset(w,'\0',100);
	memset(s,'\0',100);
	if(coll[i].word[0]!=0)
	coll[i].cont=1;
	return sum;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0;
	char w[100]={0};
	while((fscanf(in,"%s",w))!=EOF)
	{
		i=read(i,0,w);
		int k;
		for(k=1;k<=i;k++)
		{
			for(j=0;j<k;j++)
			{
				int f=2;
				f=strcmp(coll[k].word,coll[j].word);
				if(f==0 && coll[j].cont!=0)
				{
					coll[k].cont+=coll[j].cont;
					coll[j].cont=0;
					memset(coll[j].word,'\0',100);
				}
			}
		}
		i++;
	}
	qsort(coll,i,sizeof(coll[0]),cmp);
	for(j=0;j<i;j++)
	{
		if(coll[j].cont!=0)
		{
			printf("%s %d\n",coll[j].word,coll[j].cont);
		}
	}
	fclose(in);
	return 0; 
} 



