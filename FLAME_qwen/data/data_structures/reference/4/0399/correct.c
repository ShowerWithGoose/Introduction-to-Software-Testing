#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct word{
	int times;
	char w[1000];
}Word;
Word a[1000];
char s[1000],temp[1000];

int cmp(const void *a,const void *b)
{
	struct word *aa=(struct word *)a;
	struct word *bb=(struct word *)b;
	return strcmp((*aa).w,(*bb).w);
}

int main()
{
	int m=0,i,j,c,k=0,n=0;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)//将文件内容读入S 
	{
		s[m]=c;
		m++;
	}
	for(i=0;i<m;i++)//将S中所有字母换成小写 
	{
		if(isalpha(s[i]))
		s[i]=tolower(s[i]);
	}
	for(i=0;i<m;i++)
	{
		if(isalpha(s[i]))//找到每一段第一个字母 
		{
			k=0;
			for(j=i;j<m;j++)//找到每一段的最后一个字母 
			{
				if(!isalpha(s[j]))
				break;
				temp[k]=s[j];//将这一段字母暂时存入temp中 
				k++;
			}
			strcpy(a[n].w,temp);//将单词存入结构体w中 
			a[n].times=1;//出现次数初始化 
			n++;
			memset(temp,0,sizeof(temp));//中间数组temp清空 
			i=i+k-1;//移动到这一段最后一个字母 
		}
		else
		continue;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)//将相同的单词合并，次数增加 
	{
		if(a[i].times==0)
		continue;
		for(j=i+1;j<n;j++)
		{
			if(a[j].times==0)
			continue;
			if(strcmp(a[i].w,a[j].w)==0)
			{
				a[i].times++;
				memset(a[j].w,0,sizeof(a[j].w));
				a[j].times=0;
			}
		}
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
	{
		if(a[i].times!=0)
		printf("%s %d\n",a[i].w,a[i].times);
	}
	fclose(in);
	return 0;
}

