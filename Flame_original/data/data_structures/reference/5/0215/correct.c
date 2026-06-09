#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//typedef struct node_{
//	int num;
//	int live;
//	struct node_ *link;
//}node,*nodeptr;
typedef struct xiang_{
	int xi;
	int zhi;
}xiang;
int cmp(const void *p1,const void *p2);
//nodeptr creatnode2(int n);//创建循环单链表 
xiang a0[10000000];
xiang a1[1000];
xiang a2[1000];
int main()
{
	int i,j,k,l1=0,l2=0,l0=0;
	char c;
	while(1)
	{	
	  scanf("%d%d%c",&a1[l1].xi,&a1[l1].zhi,&c);
	  l1++;
	  if(c=='\n') break;
	}
	while(1)
	{	
	  scanf("%d%d%c",&a2[l2].xi,&a2[l2].zhi,&c);
	  l2++;
	  if(c=='\n') break;
	}
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		 {
		 	a0[l0].xi=a1[i].xi*a2[j].xi;
		 	a0[l0].zhi=a1[i].zhi+a2[j].zhi;
		 	l0++;
		 }
	}
	qsort(a0,l0,sizeof(xiang),cmp);
	for(i=1;i<l0;i++)
	{
		if(a0[i].zhi==a0[i-1].zhi)
		  {
		  	a0[i].xi=a0[i].xi+a0[i-1].xi;
		  	a0[i-1].xi=0;
		  }
	}
	for(i=0;i<l0;i++)
	{
		if(a0[i].xi==0) continue;
		printf("%d %d ",a0[i].xi,a0[i].zhi);
	}
	
	/*	FILE *fp1,*fp2;
	fp1=fopen("books.txt","r");
	fp2=fopen("ordered.txt","w");	
	if(fp1==NULL) 
	  {
	  	printf("Can't open the scanffile!\n'");
	   	return -1;
	  }
	if(fp2==NULL)
	   {
	   	printf("Can't open the printffile!\n'");
	   	return -2;
	   }
	memset(c,'\0',sizeof(c));	
	fclose(fp1);
	fclose(fp2);*/ 
	
//	if(freopen("output.txt","w",stdout)==NULL)
//	   {
//	   	printf("Can't open the printffile!\n'");
//	   	return -2;
//	   }
//  fclose(stdin);
//	fclose(stdout);
	return 0;
}

//nodeptr creatnode2(int n)//创建循环单链表
//{
//	int i;
//	nodeptr p,q,list;
//	list=(nodeptr)malloc((sizeof(node)));
//	list->num=1;list->live=1;list->link=NULL;
//	p=list;
//	for(i=2;i<=n;i++)
//	{
//		q=(nodeptr)malloc((sizeof(node)));
//	    q->num=i;q->live=1;q->link=NULL;
//	    p->link=q;
//	    p=q;
//	}
//	p->link=list;
//	return list;
// } 

int cmp(const void *p1,const void *p2)
{
	int w1=((xiang*)p1)->zhi;
	int w2=((xiang*)p2)->zhi;
	int ans;
	ans=w2-w1;
	return ans;
}


