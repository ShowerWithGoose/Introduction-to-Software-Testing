#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define huan(c) (c>='A' && c<='Z' ? 'a'-'A'+c:c)
struct fc
{
	int num;//记录次数 
	char f[1200];//记单词 
};
char line[1024],s[1200];
struct fc a[12000];
int pan(char x)//判断是不是字母 
{
	if(x<='Z'&&x>='A')return 1;
	if(x<='z'&&x>='a')return 1;
	return 0;
}
char*read(int i)//读取连续的字母（全转换为小写），把读过的用空格覆盖，防止重复读取 
{
	int k;
	char *word;
	word=(char*)malloc(sizeof(char)*47);
	for(k=0;pan(line[i])==1;i++,k++)
	{
		word[k]=huan(line[i]);
		line[i]=' ';
	}
	word[k]='\0';

	return word;
}
int cmp(const void*a1,const void*b1)
{
	return strcmp(((struct fc*)a1)->f,((struct fc*)b1)->f);
}
int main()
{
	FILE*in;
	in=fopen("article.txt","r");
	int i,j=0,k;
	while(fgets(line,1024,in)!=NULL)
	{
		for(i=0;line[i]!='\0';i++)
		{
			if(pan(line[i]))
			{
				if(j==0)
				{
					strcpy(a[0].f,read(i));
					a[0].num=1;
					j++;
				}
				else
				{
					strcpy(s,read(i));
					for(k=0;k<j;k++)//遍历一遍已有的单词，看是不是已经存在了 
						if(strcmp(s,a[k].f)==0)
						{
							a[k].num++;
							break;
						}
					if(k==j)
					{
						strcpy(a[j].f,s);
						a[j].num=1;
						j++;
					}
				}
			}
		}
	}
	qsort(a,j,sizeof(a[0]),cmp);//排序（用的strcmp） 
	for(i=0;a[i].num!=0;i++)
	{
		printf("%s %d\n",a[i].f,a[i].num);
		//if(i!=j-1)
		//	printf("\n");
	}
	fclose(in); 
	return 0;
}



