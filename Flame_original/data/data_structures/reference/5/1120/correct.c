#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 200
struct duo{
	int coe;
	int exp;
}; 
typedef struct duo DUO;
//读入（两个结构体数组
//逐项遍历并相乘（新开结构体数组 
//（排序）去重+合并 
//格式化输出 1.系数为零不输出  2.

int cmp(const void *a,const void *b)
{
	DUO *pa=(DUO*)a;
	DUO *pb=(DUO*)b;
    return -(pa->exp)+(pb->exp);
}

int main()
{
	DUO s[N],t[N],a[N];
	int i=0,j=0,k=0;
	int n1=0,n2=0;//n1，n2为个数 
	char ch;
//	do{
//		scanf("%d%d%c",&s[i].coe,&s[i].exp,&ch);
//		i++;
//	}while(ch!='\n');
//	do{
//		scanf("%d%d%c",&s[j].coe,&s[j].exp,&ch);
//		j++;	
//	}while(ch!='\n');
    while(scanf("%d%d",&s[n1].coe,&s[n1].exp)!=EOF)
    {
    	n1++;
    	if((ch=getchar())=='\n')
    	break;
	}
	
	while(scanf("%d%d",&t[n2].coe,&t[n2].exp)!=EOF)
    {
    	n2++;
    	if((ch=getchar())=='\n')
    	break;
	}
	
//	for(i=0;i<n1;i++)
//	printf("%d %d\n",s[i].coe,s[i].exp);
	
	qsort(s,n1,sizeof(DUO),cmp);
	qsort(t,n2,sizeof(DUO),cmp);
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			a[k].coe=s[i].coe*t[j].coe;
			a[k].exp=s[i].exp+t[j].exp;
			k++;
		 } 
	}
	
	qsort(a,k,sizeof(DUO),cmp);
	
//	for(i=0;i<k;i++)
//	printf("%d %d\n",a[i].coe,a[i].exp);
	
	for(i=0;i+1<k;i=j)	
	{
		j=i+1;
		while(a[j].exp==a[i].exp)
		{
			a[i].coe+=a[j].coe;
			a[j].coe=0;
			j++;
		}	
	}
	
	for(i=0;i<k;i++)
	{
		if(a[i].coe!=0)
		printf("%d %d ",a[i].coe,a[i].exp);
	}
	return 0;
 } 

