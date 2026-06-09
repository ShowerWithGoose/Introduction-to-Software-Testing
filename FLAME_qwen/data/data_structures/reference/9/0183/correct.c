/*#include<stdio.h>

//typedef struct lines
//{
	int x1[100];
	int y1[100];
	int x2[100];
	int y2[100];
//}line[100];

int a[100];

int main()
{
	//struct lines line[100];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if((line[i].x2==line[j].x1)&&(line[i].y2==line[j].y1))
			{
				a[j]=a[i]+1;
				line[j].x1==line[i].x1;
				line[j].y2==line[i].y1;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			line[i+1].x1=line[i].x1;
			line[i+1].x2=line[i].x2;
			line[i+1].y2=line[i].y2;
			line[i+1].y1=line[i].y1;
			a[i+1]=a[i];
		}
	}
	printf("%d %d %d\n",a[n-1],line[n-1].x1,line[n-1].y1);
	
	
	return 0;
	
}*/







/*#include<stdio.h>

//typedef struct lines
//{
	int x1[100];
	int y1[100];
	int x2[100];
	int y2[100];
//}line[100];

int a[100];

int main()
{
	//struct lines line[100];
	int n,i,j;
	int num=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((x2[i]==x1[j])&&(y2[i]==y1[j]))
			{
				a[i]++;
				a[j]=a[i];
				num++;
				x1[j]=x1[i];
				y1[j]=y1[i];
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			x1[i+1]=x1[i];
			x2[i+1]=x2[i];
			y1[i+1]=y1[i];
			y2[i+1]=y2[i];
			a[i+1]=a[i];
		}
	}
	printf("%d %d %d\n",a[n-1],x1[n-1],y1[n-1]);
	
	
	return 0;
	
}*/

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct seg				
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;					
}seg[132];



int cmpfuc(const void *a, const void *b)		
{													
    struct seg *c = (seg *)a;						
    struct seg *d = (seg *)b;
    if(c->x1!=d->x1) return d->x1 - c->x1;
    else return d->y1 - c->y1;
}
int main()
{
    struct seg seg[132];
    int n;
    scanf("%d",&n);										
    int i,j;
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2),seg[i].num = 1;

    qsort(seg,n,sizeof(seg[0]),cmpfuc);					

    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)					
        {											
            if(seg[i].x1==seg[j+1].x2 && seg[i].y1 == seg[j+1].y2)
            {
                seg[j+1].num += seg[i].num;
            }
        }
    }
    int max = -1; int flag = 0;
    for(i = 0; i < n; i++)
    {
        if(seg[i].num > max)
            max = seg[i].num,flag = i;				
    }
    printf("%d %d %d",max,seg[flag].x1,seg[flag].y1);	
    return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lines
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	

} line[200];

int cmp(const void*a,const void*b)
{
	struct lines *c=(struct lines*)a;
	struct lines *d=(struct lines*)b;
	if (c->x1!=d->x1)
	{
		return d->x1-c->x1;
	}
	else return d->y1-c->y1;
	
}

int cmp_num(const void*e,const void *f)
{
	struct lines *g=(struct lines*)e;
	struct lines *h=(struct lines*)f;

	return h->num-g->num;
}

int main()
{
	struct lines line[200];
	int n,i,j;
	scanf("%d",&n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].num=1;
	}
	qsort(line,n,sizeof(line[0]),cmp);

	for ( i = 0; i < n-1; i++)
	{
		for ( j = i; j < n-1; j++)
		{
			if (line[i].x1==line[j+1].x2 && line[i].y1==line[j+1].y2)
			{
				line[j+1].num+=line[i].num;
			}
			
		}
		
	}

	qsort(line,n,sizeof(line[0]),cmp_num);

	printf("%d %d %d\n",line[0].num,line[0].x1,line[0].y1);

	return 0;

	
	

}







