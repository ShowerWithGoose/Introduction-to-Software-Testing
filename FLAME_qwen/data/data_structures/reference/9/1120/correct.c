//连续线段
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 200
typedef struct node{
	int x1,x2,y1,y2;
	int num;//初始值为0，若建立节点则置为一
	//若有相连的则前边的置为0后边的注意加num前 
}Node;
Node row[N];

int cmp3(const void *p1, const void *p2)
{
    struct node *x = (struct node *)p1;
    struct node *y = (struct node *)p2;
    if (x->x1!= y->x1)
        return x->x1 - y->x1;//升序 
    return x->y1-y->y1;//第二关键字 
};//结构体排序 
int cmp1(const void *p1, const void *p2)
{
    struct node *x = (struct node *)p1;
    struct node *y = (struct node *)p2;
    if (x->num!= y->num)
        return y->num - x->num;//降序 
};//结构体排序 
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&row[i].x1,&row[i].y1);
		scanf("%d%d",&row[i].x2,&row[i].y2);
		row[i].num=1;
	}
	qsort(row,n,sizeof(Node),cmp3);
	for(i=0;i<n;i++)
	{
		for(j=1;i+j<n;j++)
		{
			if(row[i+j].x1==row[i].x2&&row[i+j].y1==row[i].y2)
			{
				row[i].x2=row[i+j].x2;
				row[i].y2=row[i+j].y2;
				row[i].num+=row[i+j].num;
				//row[i].num++;
				row[i+j].x1=row[i+j].x2=row[i+j].y1=row[i+j].y2=0;

			}
			else if(row[i+j].x1>row[i].x2)
			break;
		}
	}
	
	qsort(row,n,sizeof(Node),cmp1);//长度降序 
	printf("%d %d %d\n",row[0].num,row[0].x1,row[0].y1);
	return 0; 
 } 
 



