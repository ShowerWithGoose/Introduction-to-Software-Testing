#include<stdio.h>
#include<stdlib.h>
struct xian{
	int num;
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
	struct xian *next1, *next2, *next3;
}m[100], *head[100], *headmax;
int tongji(struct xian *);
int max=1;
int main()
{
	int s1, s2, s3, s4;
	int n, i, j, k=0;
	
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d%d%d", &s1, &s2, &s3, &s4);
		m[i].num=0;
		m[i].x1=s1;
		m[i].y1=s2;
		m[i].x2=s3;
		m[i].y2=s4;
		m[i].flag=0;
		m[i].next1=m[i].next2=m[i].next3=NULL;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(j==i) continue;
			if(m[i].x2==m[j].x1 && m[i].y2==m[j].y1) //i在前j在后可连接 
			{
				if(m[i].next1==NULL) m[i].next1=&m[j];
				else if(m[i].next2==NULL) m[i].next2=&m[j];
				else m[i].next3=&m[j];
				if(m[i].flag>=0)
				{
					if(m[j].flag>0) head[m[j].flag-1]=&m[i]; //如果j上有head指针，则把该指针移过来 
					else
					{
						head[k]=&m[i];
						m[i].flag=k+1; //标注 第几个head指针 
						k++;
					}
				}
				m[j].flag=-1; //表明j不是头 不可能有head指针了 
			}
		}
	} //线段排序完毕 
	
	for(i=0; i<k; i++)
	{
		head[i]->num=1;
		if(tongji(head[i])==1) headmax=head[i];
	}
	
	printf("%d %d %d", max, headmax->x1, headmax->y1);
	return 0;
}


int tongji(struct xian *t)
{
	int f=0, F;
	if(t->next1!=NULL)
	{
		(t->next1)->num=(t->num)+1;
		f=tongji(t->next1);//从 t->next1 继续往下统计
		if((t->next1)->num>max)
		{
			f=1; //给head标注headmax 
			max=(t->next1)->num;
		}  
	}
	if(t->next2!=NULL)
	{
		(t->next2)->num=t->num+1;
		f=tongji(t->next2);
		if((t->next2)->num>max)
		{
			f=1; 
			max=(t->next2)->num;
		}
	}
	if(t->next3!=NULL)
	{
		(t->next3)->num=t->num+1;
		f=tongji(t->next3);
		if((t->next3)->num>max)
		{
			f=1;
			max=(t->next3)->num;
		}
	}
	return f;
}




