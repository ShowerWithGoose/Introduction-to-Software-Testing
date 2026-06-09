#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct word{
	char ci[500];
	int pin;
};
typedef struct word W;
char s1[5000],s2[5000];
char c;
W s3[5000];
int cmp(const void*a,const void*b)
{
	struct word*c=(struct word*)a;
	struct word*d=(struct word*)b;
	return strcmp(c->ci,d->ci);
}
int main()
{
	int i=0,j,k,cnt=0;
	FILE *in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		s1[i]=c;
		i++;
	}
	for(i=0;i<strlen(s1);i++)
	{
		if(isalpha(s1[i])!=0)
		{
			s1[i]=tolower(s1[i]);
		}
	}
	for(i=0;i<strlen(s1);i++)
	{
		k=0;
		if(isalpha(s1[i])!=0)
		{
			for(j=i;j<strlen(s1);j++)
			{
				if(isalpha(s1[j])!=0)
				{
				    s2[k]=s1[j];
				    k++;
				}
				else
				    break;
			}
			strcpy(s3[cnt].ci,s2);
			memset(s2,0,sizeof(s2));
			cnt++;
			i=j;
		}
		else
		    continue;
	}
	qsort(s3,cnt,sizeof(W),cmp);
	for(i=0;i<cnt;i++)
	{
		s3[i].pin=1;
	}
	for(i=0;i<cnt;i++)
	{
		if(strcmp(s3[i].ci,s3[i+1].ci)==0)
		{
			s3[i+1].pin+=s3[i].pin;
			s3[i].pin=0;
		}
	}
	qsort(s3,cnt,sizeof(W),cmp);
	for(i=0;i<cnt;i++)
	{
		if(s3[i].pin!=0)
		{
			printf("%s %d\n",s3[i].ci,s3[i].pin);
		}
	}
	fclose(in);
	return 0;
}

