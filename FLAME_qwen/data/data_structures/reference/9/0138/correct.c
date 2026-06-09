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
//46	5	C:\Users\hzt\Desktop\college\数据结构\3\line.c	[Error] stray '\243' in program
int flagg[200];
int main()
{
	
	struct node{
	int x,xx,y,yy;
	struct node *next;
	int value;
}line[200];////////////如果用def   ？ 
	struct node *p[200],*r; 
	//r=(struct node*)malloc(sizeof(struct node));
	int i,j,max,t,x,xx,y,yy,o,flag=0;
	for(i=0;i<200;i++)
	{
		line[i].next=NULL;
		p[i]=&line[i];
		line[i].value=0;
	 } ////初始化的问题？ 
	int n,cnt=0;
	scanf("%d",&n);
	r=(struct node*)malloc(sizeof(struct node));
	//return 0;
	scanf("%d%d%d%d",&r->x,&r->y,&r->xx,&r->yy);///////////////
	line[0].next=r;
	p[0]=p[0]->next;
	line[0].value++;
	//free(r);
	//return 0;
	for(i=1;i<n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));//////r可以用来重复申请空间吗   在前面有free的情况下 
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		for(j=0;j<=cnt;j++)
		{
			if(x==p[j]->xx&&y==p[j]->yy)
			{
				r->x=x,r->y=y,r->xx=xx,r->yy=yy; 
				p[j]->next=r;
				p[j]=p[j]->next;
				line[j].value++;
				flag=1;
				break;
			}
			else if(line[j].next->x==xx&&line[j].next->y==yy)
			{
				//r=(struct node*)malloc(sizeof(struct node)); 
				r->x=x,r->y=y,r->xx=xx,r->yy=yy; 
				r->next=line[j].next;
				line[j].next=r;
				line[j].value++;
				flag=1;
				break;
			}
			else continue;
			
		}
		if(flag==0)
		{
				r->x=x,r->y=y,r->xx=xx,r->yy=yy; 
				o=cnt+1;//这里有问题 
				line[o].next=r;
				p[o]=p[o]->next;
				line[o].value++;
				cnt++;/////////////////////////////////不要担心不能用o=cnt++   这里cnt就是线段组数的下标即cnt就是最后一组线段的下标 
		} 
		flag=0; 
		
		//free(r);
	} 
	for(i=0;i<=cnt;i++)
	{
		if(flagg[i]==1) continue;
		for(j=0;j<=cnt;j++)
		{
			if(flagg[j]==1) continue;
			if(line[j].next->x==p[i]->xx&&line[j].next->y==p[i]->yy)
			{
				p[i]->next=p[j];
				line[i].value+=line[j].value;
				p[i]=p[i]->next;
				//free(p[j]);//这个怎么清除？？？
				flagg[j]=1; 
			}
			else if(p[j]->xx==line[i].next->x&&line[i].next->y==p[j]->yy)
			{
				p[j]->next=p[i];
				p[j]=p[j]->next;////////此时p【j 指向p【i 
				line[j].value+=line[i].value;
			//free(p[i]);
				flagg[i]=1; 
			} 
			else continue;
		}
	} 
	max=-1;
	for(i=0;i<=cnt;i++)///////////////////////历时四个小时的错误点竟是cnt这个线段组数变量的大小问题 
	{
		if(max<line[i].value&&flagg[i]==0)
			{
				max=line[i].value;t=i;
			}
	}
	printf("%d %d %d",max,line[t].next->x,line[t].next->y);
	//
	 
	return 0;//这道题不好用链表  因为  按顺序输入的线段不一定能够放在一起 
}


