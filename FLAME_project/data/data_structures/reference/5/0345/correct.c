#include <stdio.h>
#include <stdlib.h>
struct node{
	int index;//指数 
	int coe;//系数 
	int right;
};
struct node num1[1000000];
struct node num2[1000000];
struct node end[10000000];
int cmp(const void * a, const void * b)
{
	struct node *px,*py;
	px=(struct node *)a;   
  	py=(struct node *)b;   
    if (px->index < py->index)
        return 1;
    else if (px->index > py->index)
        return -1;
    return 0;
}

int main()
{
	int i=0,j;
	int cnt1,cnt2; 
	char c;
	
	//多项式的读入 分别存到num1和num2 
	do
	{
		i++;
		scanf("%d %d",&num1[i].coe,&num1[i].index);
	}while((c = getchar()) != '\n');
	cnt1=i;
	i=0;
	
	do
	{
		i++;
		scanf("%d %d",&num2[i].coe,&num2[i].index);
	}while((c = getchar()) != '\n');
	cnt2=i;


	//相乘后加到一起 
	int cnt=1;
	for(i=1;i<=cnt1;i++)
	{
		for(j=1;j<=cnt2;j++)
		{
			end[cnt].coe=num1[i].coe*num2[j].coe;
			end[cnt].index=num1[i].index+num2[j].index;
			cnt++;
		}
	} 
	cnt--;
	qsort(end+1,cnt,sizeof(end[0]),cmp);

	//放right数组 指右边的位置 
	for(i=1;i<=cnt;i++)
	{
		end[i].right=i+1;
	}
	end[i].index=-1;//让最后一个的右边的元素index和coe是-1 后面好判断 
	end[i].coe=-1;
//	for(i=1;i<=cnt;i++)
//	{
//		printf("%d %d %d\n",end[i].coe,end[i].index,end[i].right);
//	}
	
	i=1;
	while(end[end[i].right].index!=-1)
	{
		//下一个指数与当前的指数相同or下一个系数为零（因为系数为0所以加上也没关系） 
		while(end[i].index==end[end[i].right].index||end[end[i].right].coe==0) 
		{
			end[i].coe+= end[end[i].right].coe; //下一个的系数加到现在的 
			end[i].right=end[end[i].right].right;//删除下一个元素 
		}
		i=end[i].right;
	}
	
	i=1;
	while(end[i].index!=-1)
	{
		printf("%d %d ",end[i].coe,end[i].index);
		i=end[i].right;
	}
	
	return 0;
}

