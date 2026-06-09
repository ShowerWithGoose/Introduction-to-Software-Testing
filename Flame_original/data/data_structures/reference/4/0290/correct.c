#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word
{
	char w[50];
	int t;
};
char b[200000][30];

int cmp(const void *a,const void *b)
{
	struct word *aa=(struct word *)a;
	struct word *bb=(struct word *)b;
	if( strcmp((*aa).w,(*bb).w)>0 )
		return 1;
	return -1;
}
int main()
{
	struct word a[100] = {};
	FILE * in = fopen("article.txt","r");

	if(in == NULL)
	{
		perror("打开文件时发生错误");
		return(-1);
	}

	int i=0,j=0;
	int c = 0;
	while((c=fgetc(in))!=EOF)
	{
		if(c>='a'&&c<='z')
			b[i][j++]=c;
		else if(c>='A'&&c<='Z')
			b[i][j++]=c-'A'+'a';
		else
		{
			j=0;
			i++;
		}
	}

	int num=0;
	for(int k=0; k<=i; k++)
	{
		if(b[k][0]!='\0')
		{
			int flag = 1;
			for(int o=0; o<=num && flag; o++)
			{
				if(strcmp(b[k],a[o].w)==0)
				{
					a[o].t++;
					flag = 0;
				}
			}
			if (flag)
			{
				strcpy(a[num].w,b[k]);
				a[num++].t++;
			}
		}
	}
	qsort(a,num,sizeof(a[0]),cmp);
	for(int k=0; k<num; k++)
		printf("%s %d\n",a[k].w,a[k].t);
	fclose(in);
	return 0;
}

