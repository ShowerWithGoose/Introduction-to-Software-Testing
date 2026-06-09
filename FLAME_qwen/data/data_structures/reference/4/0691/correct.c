#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxline 1024
struct statics{
	char ctt[50];
	int num;
}st[10000];
int cmp(const void*a,const void*b)
 {
 	struct statics c=*(struct statics*)a;
 	struct statics d=*(struct statics*)b;
 	if(strcmp(c.ctt,d.ctt)<0) return-1;
 	else if(strcmp(c.ctt,d.ctt)>0) return 1;
 	return 0;
 }
int main()
{
	int i,sum=0,j;
	for(i=0;i<10000;i++) st[i].num=0;
	FILE *in;
	in=fopen("article.txt","r");
	char s0[5000];
	while(fgets(s0,maxline,in)!=NULL)
	{
		
		for(i=0;i<strlen(s0);i++)
    	{
		if(s0[i]>='a'&&s0[i]<='z') s0[i]=s0[i];
		else if(s0[i]>='A'&&s0[i]<='Z') s0[i]=s0[i]-'A'+'a';
		else s0[i]='0';
     	}
     	//printf("%s\n",s0);
     	char s1[5000];
     	for(i=0;i<strlen(s0);)
     	{
     		int k=0;
		    if(s0[i]!='0')
			{
				while(s0[i+k]!='0')
				{
					s1[k]=s0[i+k];
					k++;
				}
				s1[k]='\0';
				int count=0;
				for(j=0;j<sum;j++)
				{
					if(strcmp(st[j].ctt,s1)==0)
					{
						count=1;
						st[j].num++;
						break;
					}
				}
				if(count==0)
				{
					for(j=0;j<=k;j++)
					{
						st[sum].ctt[j]=s1[j];
					}
					st[sum].num=1;
					sum++;
				}
				i+=k;
			}
			else i++; 	
		}
	}
	qsort(st,sum,sizeof(st[0]),cmp);
	for(i=0;i<sum;i++) printf("%s %d\n",st[i].ctt,st[i].num);
	return 0;
}

