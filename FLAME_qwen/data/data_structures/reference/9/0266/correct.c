#include<stdio.h>
#include<stdlib.h>
typedef struct line{
	int x1,y1,x2,y2;
	int key;
	struct line *link;
} Line;
int main()
{
	int n,i,j,k,flag,m,count,countmax=0;
	Line *l[105],tep,*p[105],*q[105],*r[105],*tep1,Max;
	scanf("%d",&n);
	for(i=0,j=0;i<n;i++)
	{
		flag = 0;
		scanf("%d %d %d %d",&tep.x1,&tep.y1,&tep.x2,&tep.y2);
		for(k=0;k<j;k++)
		{
			if(l[k]->key==0)
			continue;
			tep1=l[k];
			if(p[k]->x2==tep.x1&&p[k]->y2==tep.y1)//在后面接一下 
			{
				*q[k]=tep;
			    p[k] = q[k];
			    q[k] = (Line*)malloc(sizeof(Line));
			    p[k]->link=q[k];
			    flag = 1;
			    break;
			}
			if(l[k]->x1==tep.x2&&l[k]->y1==tep.y2)//在前面接一下 
			{
				r[k]=(Line*)malloc(sizeof(Line));
				*r[k]=tep;
				r[k]->link=l[k];
				l[k]=r[k];
				l[k]->key=1;
				flag = 2;
				break;
			}
		}
		if(flag==1)
		{
			for(m=0;m<j;m++)
			{
				if(l[m]->key==0)
				continue;
				if(l[m]->x1==p[k]->x2&&l[m]->y1==p[k]->y2)
				{
					l[m]->key=0;
					p[k]->link=l[m];
					p[k]=p[m];
					q[k]=(Line*)malloc(sizeof(Line));
					q[k]->link=NULL;
					p[k]->link=q[k];
				}
			}
			continue;
		}
		if(flag==2)
		{
			for(m=0;m<j;m++)
			{
				if(l[m]->key==0)
				continue;
				if(p[m]->x2==l[k]->x1&&p[m]->y2==l[k]->y1)
				{
					l[k]->key==0;
					p[m]->link=l[k];
					p[m]=p[k];
					p[m]->link=q[m];
				}
			}
			continue;
		}
		l[j]=(Line*)malloc(sizeof(Line));
		*l[j]=tep;
		p[j]=l[j];
		q[j]=(Line*)malloc(sizeof(Line));
		q[j]->link=NULL;
		p[j]->link=q[j];
		p[j]->key=1;
		j++;
	}
	for(i=0;i<j;i++)
	{
		if(l[i]->key==0)
		continue;
		count=0;
		tep1=l[i];
		while(tep1->link!=NULL)
		{
			count++;
			tep1=tep1->link;
		}
		if(count>countmax)
		{
			countmax = count;
			Max.x1=l[i]->x1;
			Max.y1=l[i]->y1;
		}
	}
	printf("%d %d %d\n",countmax,Max.x1,Max.y1);
	return 0;
}

