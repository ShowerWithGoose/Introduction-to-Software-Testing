#include<stdio.h>
#include<stdlib.h>
#define MAX 65536
struct node{
	int xs;
	int ys;
	int xe;
	int ye;
	int len;
}s[108];//存输入 
struct Node{
	int X1;
	int Y1;
	int X2;
	int Y2;
}t[108];//连续线段 
int cmp(const struct Node*p1,const struct Node *p2)
{
	if(p1->X1<p2->X1)return -1;
	else if(p1->X1>p2->X1)return 1;
	return 0;
} 
//short a[MAX];
//short b[MAX];
int main()
{
	int T;
	int n=0;
	int i,j,k=1,f=0;
	int max=-1,x;
	scanf("%d",&T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&t[i].X1,&t[i].Y1,&t[i].X2,&t[i].Y2);
		n++;
	}
	qsort(t,n,sizeof(t[0]),cmp);//把x按照从小到大排列 
	
	s[0].xs=t[0].X1;
	s[0].ys=t[0].Y1;
	s[0].xe=t[0].X2;
	s[0].ye=t[0].Y2;//组建第一条连续线段 
	s[0].len=1; 
	for(i=1;i<T;i++)
	{
		f=0;
		for(j=0;j<k;j++)
		{
			if(s[j].xe==t[i].X1&&s[j].ye==t[i].Y1)//如果连续线段结尾和这个相同 
			{
				s[j].xe=t[i].X2;
				s[j].ye=t[i].Y2;//把连续线段的结尾改称2，并将连续线段的长度+1 
				s[j].len++;
				f=1;
				break;//接在末尾 
			}
		/*	if(s[j].xs==t[i].X2&&s[j].ys==t[i].Y2)
			{
				s[j].xs=t[i].X1;
				s[j].ys=t[i].Y1;
				s[j].len++;
				f=1;
				break; 
			}*/
		}
		if(f==0)//如果没有找到，就新开一个s 
		{
			s[k].xs=t[i].X1;
			s[k].ys=t[i].Y1;
			s[k].xe=t[i].X2;
			s[k].ye=t[i].Y2;
			s[k].len=1;
			k++;//k表示连续线段的组数 
		}
	}
	for(i=0;i<k;i++)
	{
		if(s[i].len>max)
		{
			max=s[i].len;
			x=i;//找出len最长的s[i] 
		}
	}
	printf("%d %d %d",s[x].len,s[x].xs,s[x].ys);
	return 0;
}

