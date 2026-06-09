//3-1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct segment{
	int xstart;
	int ystart;
	int xend;
	int yend;
	struct segment *next;
}; 
struct line{
	struct segment *head;
	struct segment *tail;
	int sumseg;
};
int main()
{
	int N,i,j,maxsum=0,mark=-1,flag;
	scanf("%d",&N);
	struct segment *s[100];//段结构指针数组 
	struct line l[100];//线结构数组 
	for(i=0;i<N;i++)
	{//读入段并把每个段设为线 
		s[i]=(struct segment*)malloc(sizeof(struct segment));
		scanf("%d%d%d%d",&s[i]->xstart,&s[i]->ystart,&s[i]->xend,&s[i]->yend);
		s[i]->next=NULL;
		l[i].head=s[i];
		l[i].tail=s[i];
		l[i].sumseg=1;
	}
	for(i=0;i<N;i++)
	{//遍历线
		flag=0;
		if(l[i].head==NULL&&l[i].tail==NULL)
			continue; 
		for(j=0;j<N;j++)
		{//把第j个线与第i个线相连 
			if(j==i)
				continue;
			if(l[j].head==NULL&&l[j].tail==NULL)
				continue; 
			if(l[j].head->xstart==l[i].tail->xend&&l[j].head->ystart==l[i].tail->yend)
			{
				l[i].tail->next=l[j].head;
				l[j].head=l[i].head;
				l[j].sumseg+=l[i].sumseg;
				l[i].sumseg=0;
				flag=1;
			}
			else if(l[i].head->xstart==l[j].tail->xend&&l[i].head->ystart==l[j].tail->yend)
			{
				l[j].tail->next=l[i].head;
				l[j].sumseg+=l[i].sumseg;
				l[i].sumseg=0;
				flag=1;
			}
		}
		if(flag)
		{//若成功相连则消除第i个线 
			l[i].head=NULL;
			l[i].tail=NULL;
			l[i].sumseg=0;
		}
	}
	for(i=0;i<N;i++)
	{//找出最长的线 
		if(l[i].sumseg>maxsum)
		{
			maxsum=l[i].sumseg;
			mark=i;
		}
	}
	printf("%d %d %d",maxsum,l[mark].head->xstart,l[mark].head->ystart);
	for(i=0;i<N;i++)
		free(s[i]);
	return 0;
}


