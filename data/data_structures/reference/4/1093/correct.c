#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
	char s[30];
	int times;
};
struct node out[508];
char in[1008][30];
int cmp1(const void *p1,const void *p2)
{
	char *a=(char*)p1;
	char *b=(char*)p2;
	int x=strcmp(a,b);
	if(x<0)return 1;
	else if(x>0)return -1;
	return 0;
}
int cmp2(const struct node *p1,const struct node *p2)
{
	int x=strcmp(p1->s,p2->s);
	if(x>0)return 1;
	else if(x<0)return -1;
	return 0;
}
int main()
{
	FILE *f1=fopen("article.txt","r");
	
	char tmp[100];
	int i,j,k=0,t=0,len;
	while(fgets(tmp,100,f1)!=NULL)//把每个单词转换成小写读进 
	{
		len=strlen(tmp);
		for(i=0;i<len;i++)
		{
			if(isalpha(tmp[i]))
			{
				for(j=i;isalpha(tmp[j])&&j<len;j++)
				{
					tmp[j]=tmp[j]<90?tmp[j]+32:tmp[j];
					in[k][t++]=tmp[j];
				}
				i=j;
				t=0;
				k++;
			}
		}
	}
	qsort(in,k,sizeof(in[0]),cmp1);
	
//	len=k;
	t=0;
	for(i=0;i<k;i++)
	{
		strcpy(out[t].s,in[i]);
		for(j=i+1;(strcmp(out[t].s,in[j])==0)&&j<k;j++);
		out[t].times=j-i;
		t++;
		i=j-1;
	}
	qsort(out,t,sizeof(out[0]),cmp2);
	
	
	for(i=0;i<t;i++)
	{
		printf("%s %d\n",out[i].s,out[i].times);
	}
	return 0;
}

