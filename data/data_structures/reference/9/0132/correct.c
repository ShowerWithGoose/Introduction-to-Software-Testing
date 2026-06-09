#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct point{
	int x;
	int y;
	struct point *front1;
	struct point *front2;
	struct point *next1;
	struct point *next2;
	struct point *np;
}point,*ppoint;

typedef struct Result{
	int x;
	int y;
	int len;
}Result;

Result result[110];
int numr=0;

void judge(ppoint temp)
{
	int len=0,flag=0;
	
	if(temp->next1!=NULL)
	{
		len+=judge2(temp,temp->next1);
		flag=1;
	}
	if(temp->next2!=NULL)
	{
		len+=judge2(temp,temp->next2);
		flag=1;
	}
	
	if(flag==1)
	{
		result[numr].x=temp->x;
		result[numr].y=temp->y;
		result[numr].len=len;
		numr++;
	}
}

int judge2(ppoint front,ppoint temp)
{
	int len=1;
	if(temp->front1!=NULL&&((temp->front1)->x!=front->x||(temp->front1)->y!=front->y))
	{
		len+=judge2(temp,temp->front1);
	}
	if(temp->front2!=NULL&&((temp->front2)->x!=front->x||(temp->front2)->y!=front->y))
	{
		len+=judge2(temp,temp->front2);
	}
	if(temp->next1!=NULL&&((temp->next1)->x!=front->x||(temp->next1)->y!=front->y))
	{
		len+=judge2(temp,temp->next1);
	}
	if(temp->next2!=NULL&&((temp->next2)->x!=front->x||(temp->next2)->y!=front->y))
	{
		len+=judge2(temp,temp->next2);
	}
	
	return len;
}


int main()
{

	//freopen("damn.txt","r",stdin);//
	

	
	int i,n;
	scanf("%d",&n);getchar();
	ppoint first,p;
	
	first=(ppoint)malloc(sizeof(point)); 
	memset(first,0,sizeof(point));
	p=(ppoint)malloc(sizeof(point));
	memset(p,0,sizeof(point));
	
	scanf("%d %d %d %d",&first->x,&first->y,&p->x,&p->y);
	
	first->next1=p;
	p->front1=first;
	first->np=p;
	
	for(i=0;i<n-1;i++)
	{
		ppoint a,b;
		a=(ppoint)malloc(sizeof(point));
		memset(a,NULL,sizeof(point));
		b=(ppoint)malloc(sizeof(point));
		memset(b,NULL,sizeof(point));
		p->np=a;
		
		scanf("%d %d %d %d",&a->x,&a->y,&b->x,&b->y);
		a->next1=b;
		b->front1=a;
		a->np=b;
		
		p=b;
	}
	/*ppoint temp=first;
	for(i=0;i<2*n;i++)//
	{
		printf("%d %d\n",temp->x,temp->y);
		temp=temp->np;
	}*/
	
	
	
	
	//连接线段 /////////////////////////////////////
	ppoint temp=first;
	for(i=0;i<2*n;i++)
	{
		int x0=temp->x,y0=temp->y;
		int j;
		ppoint temp2=first;
		for(j=0;j<2*n;j++)
		{
			if(x0==temp2->x&&y0==temp2->y)
			{
				//前 1
				if(temp2->front1!=NULL)
				{
					if(temp->front1!=temp2->front1&&temp->front2!=temp2->front1)
					{
						if(temp->front1==NULL)
						{
							temp->front1=temp2->front1;
						}
						else
						{
							temp->front2=temp2->front1;
						}
					}
				}
				
				//前 2 
				if(temp2->front2!=NULL)
				{
					if(temp->front1!=temp2->front2&&temp->front2!=temp2->front2)
					{
						if(temp->front1==NULL)
						{
							temp->front1=temp2->front2;
						}
						else
						{
							temp->front2=temp2->front2;
						}
					}
				}
				
				//后 1 
				if(temp2->next1!=NULL)
				{
					if(temp->next1!=temp2->next1&&temp->next2!=temp2->next1)
					{
						if(temp->next1==NULL)
						{
							temp->next1=temp2->next1;
						}
						else
						{
							temp->next2=temp2->next1;
						}
					}
				}
				
				//后 2 
				if(temp2->next2!=NULL)
				{
					if(temp->next1!=temp2->next2&&temp->next2!=temp2->next2)
					{
						if(temp->next1==NULL)
						{
							temp->next1=temp2->next2;
						}
						else
						{
							temp->next2=temp2->next2;
						}
					}
				}
			}
			
			
			temp2=temp2->np;
		}
		temp=temp->np;
	}
	
	
	/*temp=first;
	for(i=0;i<2*n;i++)
	{
		temp=temp->np;
	}*/
	
	
	//检测第一根线段 /////////////////////////////////
	temp=first;
	for(i=0;i<2*n;i++)
	{
		int count=0;
		if(temp->front1!=NULL) count++;
		if(temp->front2!=NULL) count++;
		if(temp->next1!=NULL) count++;
		if(temp->next2!=NULL) count++;
		if(count==1)
		{
			judge(temp);
		}
		temp=temp->np;
	}
	
	int maxlen=0,mx,my;
	
	int k=0;
	while(result[k].len!=0)
	{
		if(result[k].len>maxlen)
		{
			maxlen=result[k].len;
			mx=result[k].x;
			my=result[k].y;
		}
		k++;
	}
	
	printf("%d %d %d",maxlen,mx,my);
	
	return 0;
}

