#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 typedef struct _multi{
	int num;
	int x;
}multi,*pmulti;
 multi equ1[100],equ2[100],sum[3000];
 int cmp(const void *p1,const void *p2){
 	pmulti pp1=(pmulti)p1;
 	pmulti pp2=(pmulti)p2;
 	if(pp1->x>pp2->x)
 	return -1;
 	else return 1;
 } 
int main()
{  int nnum,xx,i=0,j=0,k=0,count1,count2,count;
char c;
do
 { 
	scanf("%d%d%c",&nnum,&xx,&c);
	equ1[i].num=nnum;
	equ1[i].x=xx;
	i++;
 }while(c!='\n');
 count1=i;//多项式1项数 
 i=0;
 do
 {
 	scanf("%d%d%c",&nnum,&xx,&c);
 	equ2[i].num=nnum;
 	equ2[i].x=xx;
 	i++;
 }while(c!='\n');
 count2=i;//多项式2项数 
 i=0;
 count=count1*count2;//相乘后项数
 for(i=0;i<count1;i++)
 {
 	for(j=0;j<count2;j++)
 	{
 		sum[k].num=equ1[i].num*equ2[j].num;
 		sum[k].x=equ1[i].x+equ2[j].x;
 		k++;
	 }
 }
 for(i=0;i<count;i++)//合并同类项 
 {
 	for(j=i+1;j<count;j++)
 	{
 		if(sum[i].x==sum[j].x)
 		{
 		    sum[i].num=sum[i].num+sum[j].num;
 			for(k=j+1;k<count;k++)//删除第j项 
			{
				 sum[k-1]=sum[k];	
			}
			count--; 
		}
		 
	 }
 }
 qsort(sum,count,sizeof(sum[0]),cmp);//按x指数排序
 for(i=0;i<count;i++)
 {
 	printf("%d %d ",sum[i].num,sum[i].x);
  } 
     
    return 0;  
}



