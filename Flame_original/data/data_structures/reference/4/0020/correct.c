#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Word
{
	char words[100];
	int num;
}a[100];
int cmp(const void*a,const void*b)
{
	struct Word *c=(struct Word*)a;
	struct Word *d=(struct Word*)b;
	if(strcmp(c->words,d->words)<0)
		return -1;
	return 1; 
}
int main()
{
	char c,str[2000];
	int i=0,j,n=0,flag=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			c='a'+c-'A';
			str[i]=c;
			i++;
		}
		else if(c>='a'&&c<='z')//如果c是大写字母，则c在前面的if里被改成了小写字母，会再被存储一次 
		{
			str[i]=c;
			i++;
		}
		else
		{
			str[i] = '\0';//将存储的最后一个字符置为\0，不然在比较的时候，找不到结尾 
			if(strcmp(str,"\0")!=0)
			{
				for(j=0;j<n;j++)
				{
					if(strcmp(str,a[j].words)==0)
					{
						flag=1;
						a[j].num++;
						break;
					}
					else
					{
						flag=0;
					}
				}
				if(flag==0)
				{
					a[n].num=1;
					strcpy(a[n].words,str);
					n++;
				}
			}
			i=0;
		}
		
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",a[i].words,a[i].num);
	}
	fclose(fp);
	return 0;
}

