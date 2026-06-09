#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
typedef struct MOde{    
	int ID;				  	
	struct MOde *boy[4];
}Leaves,*Leavesp;
struct go{	
	int ID;	
	int size;	
}go[2000];
Leaves node[2000];
int q[1000] ;
int root,tmp,boy;
int i,j,top=0,num;
void layerorder(Leavesp t)
{
	Leavesp Queue[200],p;
	int front,dear;
	if(t!=NULL)
	{
		Queue[0]=t;
		front=-1,dear=0;
		while(front<dear)	 
		{
			p=Queue[++front];
			if(p->boy[0]==NULL && p->boy[1]==NULL && p->boy[2]==NULL)
			{
				q[top]=p->ID;
				top++;
			}
			for(i=0;i<=3;i++)
			{
				if(p->boy[i]!=NULL)
				{
					Queue[++dear]=p->boy[i];
				}
			}
		}
	}
}
int qizi[100]; 
int n,k;
int line[100][2][2];
void find(int x,int y,int j)
{
	int i;
	void digui()
	{
	for(i=0;i<n;i++)
	{
		if(i!=j)
		{
			if(x==line[i][0][0]&&y==line[i][0][1])//: x2 y2 是否等于  x1 y1
			{
				qizi[k]++; //:记录位置 并且连续次数加1 
				find(line[i][1][0],line[i][1][1],i);//:进入递归 查找后续连续 没有就退出 进入下一个j的查找 
				break;
			}
		}
	}	}digui();
}

int main()
{
	void shuru()
	{

	scanf("%d",&n);	}shuru();
	int i,j;
	void daxunhuan()
	{

	for(i=0;i<n;i++)
	{
		void sca()
		{
		scanf("%d %d %d %d",&line[i][0][0],&line[i][0][1],&line[i][1][0],&line[i][1][1]);	}sca();
	}
	for(i=0;i<n;i++)//:遍历查找 
	{
		k=i;
		find(line[i][1][0],line[i][1][1],i);
	}}daxunhuan();
	int max_num=0,max_first=0;	
	void bianli()
	{
	for(i=0;i<n;i++)//:遍历qizi 寻找最大的qizi 也就是连续次数  
	{
		max_num=max(qizi[i],max_num); 
	}
	for(i=0;i<n;i++)//:遍历qizi 寻找最大的qizi对应的线段
	{
		if(qizi[i]==max_num)
		{
			max_first=i;
			break;
		}
	}	}bianli();
	printf("%d %d %d",max_num+1,line[max_first][0][0],line[max_first][0][1]);
	return 0;
}



