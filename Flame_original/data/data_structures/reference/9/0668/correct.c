#include<stdio.h>
#include<stdlib.h>
struct node{
	int x1;
	int y1;
	int x2;
	int y2;
} xianduan[105];

struct Node{
	int x1;
	int y1;
	int num;
}xian[55];
int cmp(const void *a,const void *b)
{
	return(*(int*)a)>(*(int*)b)?1:-1;
}

int cmp1(const void *a,const void *b)
{
	return -((int*)a)[0]+((int*)b)[0];
}
int main(){
	int count;
	scanf("%d",&count);
	
	int i=0;
	for(i=0;i<count;i++)
	{
		scanf("%d %d %d %d",&xianduan[i].x1,&xianduan[i].y1,&xianduan[i].x2,&xianduan[i].y2);
	}
	
	qsort(xianduan,count,sizeof(xianduan[0]),cmp);
	
//	int n=0;
//	for(n=0;n<count;n++)
//	printf("%d %d\n",xianduan[n].x1,xianduan[n].y1);
	int j=0;
	int a[55][3];
	for(i=0;i<count;i++){
		xian[i].x1=xianduan[i].x2;
		xian[i].y1=xianduan[i].y2;
		xian[i].num=1;
		a[i][1]=xianduan[i].x1;
		a[i][2]=xianduan[i].y1;
		a[i][0]=1;
		int j=0;
		for(j=0;j<count;j++)
		{
			if(i==j){			}
			else if(xian[i].x1==xianduan[j].x1&&xian[i].y1==xianduan[j].y1)
			{
				xian[i].x1=xianduan[j].x2;
				xian[i].y1=xianduan[j].y2;
			//	xian[i].num++;
			a[i][0]++;
				int tem; 
				for(tem=j;tem<count;tem++)
				{
					xianduan[tem].x1=xianduan[tem+1].x1;
					xianduan[tem].x2=xianduan[tem+1].x2;
					xianduan[tem].y1=xianduan[tem+1].y1;
					xianduan[tem].y2=xianduan[tem+1].y2;
				}
				count--;
				j--;
			}
		}
	//	a[i][0]=xian[i].num;
	}
	qsort(a,i,sizeof(int)*3,cmp1);
	int m=0;
	//for(;m<i;m++)
	printf("%d %d %d\n",a[m][0],a[m][1],a[m][2]);
}




















