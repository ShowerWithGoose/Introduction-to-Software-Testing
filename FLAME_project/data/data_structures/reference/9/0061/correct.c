#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct location{
	int bx;
	int by;
	int ex;
	int ey;
	int num;       
};
typedef struct location w;
w l[2000];
int cmp(const void*p1,const void*p2);
int cmpm(const void*p1,const void*p2);
int main()
{	
	int n,a,b,c,d;
	int i,j,k=0,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) l[i].num=1;  
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&l[i].bx,&l[i].by,&l[i].ex,&l[i].ey);
	}
	qsort(l,n,sizeof(w),cmpm);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;  
			}
			else
			{
				if(l[j].bx == l[i].ex && l[j].by == l[i].ey) 
				{
					l[i].ex = l[j].ex;		
					l[i].ey = l[j].ey;      
					l[i].num += l[j].num;   
					l[j].bx=0,l[j].by=0,l[j].ex=0,l[j].ey=0,l[j].num=0;
				}
			}
			
		}
	}
	for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)					
        {											
            if(l[i].bx==l[j+1].ex && l[i].by == l[j+1].ey)
            {
                l[j+1].num += l[i].num;
            }
        }
    }
    
	qsort(l,n,sizeof(w),cmp); 
	printf("%d %d %d\n",l[n-1].num,l[n-1].bx,l[n-1].by);
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct location *a=(struct location*)p1;
	struct location *b=(struct location*)p2;
	return a->num-b->num;
}
int cmpm(const void*p1,const void*p2)
{
	struct location *a=(struct location*)p1;
	struct location *b=(struct location*)p2;
	if(a->bx != b->bx) return a->bx-b->bx;
	else return a->by-b->ey;
}


