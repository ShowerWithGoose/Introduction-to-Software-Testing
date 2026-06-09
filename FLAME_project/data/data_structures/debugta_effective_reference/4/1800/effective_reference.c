#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aaa
{
	int n;
	char w[100];
}a[100000];
int cmp(const void *x,const void *y)
{
	struct aaa p=*(struct aaa*)x;
	struct aaa q=*(struct aaa*)y;
	return strcmp(p.w,q.w);
}
int main()
{
	char x[10000],k[100];///////b存句子 
	int i=0,l,j=0,flag;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(x,10000,in)!=NULL)
	{
		l=strlen(x);
		for(int q=0;q<l;q++)
		if(x[q]>='A'&&x[q]<='Z')
		x[q]=x[q]-'A'+'a';/////b全部转成小写 
		for(int q=0;q<l;q++)
		{
			if(x[q]<'a'||x[q]>'z')
			continue;///////跳过所有垃圾字符     可以回避getchar对空字符等的读取错误     
			for(int j=0;;j++)
			{
				if(x[q+j]>='a'&&x[q+j]<='z')///////会不会b数组越界？ 
				{
					k[j]=x[q+j];
					j++;
				}
				else
				{
					flag=1;
					for(int k=0;k<i;k++)//////一个单词找到，进行单词表的检索 
					if(strcmp(k,a[k].w)==0)
					{
						flag=0,a[k].n++;break;
					}
					if(flag)//////新单词 
					{
						strcpy(a[i].w,k);
						a[i].n=1;
						i++;
					}
					memset(k,0,sizeof(k));j=0;
					q=q+j;
					break;
				}
			}
		}
	}
	qsort(a,i,sizeof(a[0]),cmp);
	for(int q=0;q<i;q++)
	printf("%s %d\n",a[q].w,a[q].n);
}



