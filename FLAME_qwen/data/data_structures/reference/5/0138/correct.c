#include<time.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define eps 1e-5
//注意flag和qsort的组合用法（用结构体套flag）
//break和continue的深思熟虑
//freopen 不是万能的
///////结构体数组作为函数参数来传递时  并不是像普通数组一样作为地址    这点一定注意
//循环时的数组下标 和自加的顺序 一定不要弄错
///传递的地址在函数中操作时：1.在给定的地址对应的内存单元上操作 2.在函数中用新指针但是操作中未涉及对指针对应的地址的数据操作则相当于跨函数的无效操作
///有关双变量i j 的搜索一定要注意i和j的两种情况都要跟进
//14：58 
int i,j,k,l1,l2,x1,x2,flag,cnt;
int aa[10000],bb[10000];
char ch;
struct aa{
	int xi;
	int zhi;
	int flag;
}a[1000],b[1000],c[10000]; 
int cmp(const void *e1,const void *e2)
{
	struct aa* p1=(struct a*)e1;
	struct aa* p2=(struct a*)e2;
	return p2->zhi-p1->zhi;
}
int main()
{
	//gets(aa); 
//	for(i=0;i;i=i+2)////
//	{
//	/	sscanf(aa,"%d%d",&a[k].xi,&a[k].zhi));
//		k++;
//	}
//	l1=k;
//	gets(bb); 
//	k=0;
//	for(i=0;i;i=i+2)////
//	{
//		sscanf(bb,"%d%d",&b[k].xi,&b[k].zhi));
//		k++;
//	}
//	l2=k;/////////
while(1)
{
	scanf("%d%d%c",&a[k].xi,&a[k].zhi,&ch);
	k++;
	if(ch=='\n')
		break;
}
l1=k;
while(1)
{
	scanf("%d%d%c",&b[k].xi,&b[k].zhi,&ch);
	k++;
	if(ch=='\n')
		break;
}
l2=k;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			flag=0;
			x1=a[i].xi*b[j].xi;
			x2=a[i].zhi+b[j].zhi;
			for(k=0;k<cnt;k++)
			{
				if(c[k].zhi==x2)
				{
					c[k].xi+=x1;
					flag=1;
					//if(c[k].xi==0)
					//{
					//	c[k].flag=1;
				//	}
					break;
				}
			}
			if(flag==0)
			{
				c[cnt].xi=x1;
				c[cnt].zhi=x2;
				cnt++;
			}
		}
	}
	qsort(c,cnt,sizeof(c[0]),cmp);
	for(i=0;i<cnt;i++)
	{
		if(c[i].xi!=0)
			printf("%d %d ",c[i].xi,c[i].zhi);
	}
		
	return 0;
}


