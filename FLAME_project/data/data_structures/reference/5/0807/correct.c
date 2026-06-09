#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
	int x;//系数 
	int z;//指数
	struct Node *next;//指向下一个 
}*head,*p,*q,*p0,a[2000],b[2000],c[1905];
int cmp(const void *x,const void *y)
{
	struct Node *as=(struct Node *)x;
	struct Node *bs=(struct Node *)y;
return bs->z-as->z;
}
int main()
{
	int x,z,j=0,i=0,k=0,l1,l2;
	char m;
	do{
		scanf("%d%d%c",&a[i].x,&a[i].z,&m);
		i++;
      }while(m!='\n');//第一个多项式有i个元素，在0到i-1中  
    qsort(a,i,sizeof(struct Node),cmp);//把第一个按指数降序排列
       l1=i;
	do{
		scanf("%d%d%c",&b[j].x,&b[j].z,&m);
		j++;
      }while(m!='\n');//第二个多项式有j个元素，在0到j-1中  
    qsort(b,j,sizeof(struct Node),cmp);//按指数降序排列
        l2=j;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			c[k].x=a[i].x*b[j].x;
			c[k].z=a[i].z+b[j].z;
			k++;
		}
	}
	qsort(c,k,sizeof(struct Node),cmp);//最后结果的那个结构体数组也按指数降序排列
	for(i=0;i<k;i++)
	{
		while(c[i+1].z==c[i].z&&i<k-1)
		{
			c[i+1].x +=c[i].x;
			c[i].x=0;
			i++;
		}
	 } 
	 for(i=0;i<k;i++)
	 {
	 	if(c[i].x!=0)
	 	printf("%d %d ",c[i].x,c[i].z);
	 }
return 0;
}

