#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct express{
	int coe;
	int po;			
};
typedef struct express dxs;
dxs a[1000],b[1000];
dxs fin[1000]; 
int cmp(const void*p1,const void*p2);
int main()
{
    int i=0,j=0,k=0,max1,max2,max;
    char c;
    do
    {
        scanf("%d%d%c",&a[i].coe,&a[i].po,&c);
        i++;
    }while(c != '\n');
        max1 = i;
    do
    {
        scanf("%d%d%c",&b[j].coe,&b[j].po,&c);
        j++;
    }while(c != '\n');
    
    max2 = j;
    
    qsort(a,max1,sizeof(dxs),cmp);
	qsort(b,max2,sizeof(dxs),cmp);
	
    
    
    for(i=0;i<max1;i++)
	{
		for(j=0;j<max2;j++)
		{
			fin[k].coe = a[i].coe * b[j].coe;
			fin[k].po=a[i].po + b[j].po;
			k++;
		}
	}
	max = k;
	qsort(fin,k,sizeof(dxs),cmp);
	
    for(i = 0;i < k;i++)
    {
        if(fin[i].po == fin[i+1].po && fin[i].po != 0)
		{
			fin[i+1].coe += fin[i].coe;
			fin[i].coe = 0;
		}
    }
    
    	qsort(fin,k,sizeof(dxs),cmp);
    
    for(i = 0;i<k;i++)
    {
        if(fin[i].coe == 0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",fin[i].coe,fin[i].po);
		}
    }
    return 0;
}

int cmp(const void*p1,const void*p2)
{
	struct express *a=(struct express*)p1;
	struct express *b=(struct express*)p2;
	return b->po-a->po;
}


