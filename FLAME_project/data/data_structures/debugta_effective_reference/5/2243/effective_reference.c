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
	int a;
	int n;
}xiang;
int cmp(const void *p1,const void *p2);
//nodeptr creatnode2(int n);//创建循环单链表 
xiang items3[10000000];
xiang items1[1000];
xiang items2[1000];
int main()
{
	int i,j,k,l1=0,l2=0,count=0;
	char c;
	while(1)
	{	
	  scanf("%d%d%c",&items1[l1].a,&items1[l1].n,&c);
	  l1++;
	  if(c=='\n') break;
	}
	while(1)
	{	
	  scanf("%d%d%c",&items2[l2].a,&items2[l2].n,&c);
	  l2++;
	  if(c=='\n') break;
	}
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		 {
		 	items3[count].a=items1[i].a*items2[j].a;
		 	items3[count].n=items1[i].n+items2[j].n;
		 	count++;
		 }
	}
	qsort(items3,count,sizeof(xiang),cmp);
	for(i=1;i<count;i++)
	{
		if(items3[i].n==items3[i-1].n)
		  {
		  	items3[i].a=items3[i].a+items3[i-1].a;
		  	items3[i-1].a=0;
		  }
	}
	for(i=0;i<count;i++)
	{
		if(items3[i].a==0) continue;
		printf("%d %d ",items3[i].a,items3[i].n);
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
	int w1=((xiang*)p1)->n;
	int w2=((xiang*)p2)->n;
	int ans;
	ans=w2-w1;
	return ans;
}


