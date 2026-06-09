#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*pa,const void *pb);
struct word{
	char w[200];
	int cnt;
};
struct word stu[1000];
char s[10000];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	
	char c;
	char vol[200];
	memset(vol,0,sizeof(vol));
	int i=0,j=0,k=0,l=0;
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			s[i]=c-'A'+'a';
		}
		else
		{
			s[i]=c;
		}
		i++;
	}
	int len=strlen(s);//s是所有内容 已经小写
	
	for(i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			for(j=i;j<len;j++,k++)
			{		
				if(s[j]>'z'||s[j]<'a')
				{
					strcpy(stu[l].w,vol);
					l++;
					memset(vol,0,sizeof(vol));
					i+=k;
					k=0;
					break;
				}
				else
				vol[k]=s[j];
			}
		}
		else
		continue;
	}//已经将单词分开 每个单词放入结构体一个stu中
    int num=l;//单词数目； 
	qsort(stu,num,sizeof(struct word),cmp); //按字典序排序
	
	//统计重复次数，简单合并输出；
	for(i=0;i<num;i++)
	{
		if(strcmp(stu[i].w,stu[i+1].w)==0)
		{
			stu[i+1].cnt=stu[i].cnt+1;
			memset(stu[i].w,0,sizeof(stu[i].w)); 
		}
	} 
	for(i=0;i<num;i++)
	{
		if(stu[i].w[0]!=0)
		{
			printf("%s",stu[i].w);
			printf(" ");
			printf("%d\n",stu[i].cnt+1);
		}
		else
		continue;
	}
	
	
	
	
	
	
	
	
	fclose(in);
	
	
	return 0;
 } 
 int cmp(const void*pa,const void *pb)
 {
 	struct word *pd1=(struct word *)pa;
 	pd1->w;
 	struct word *pd2=(struct word *)pb;
 	pd2->w;
 	return strcmp(pd1,pd2);
 }

