#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LINK{
	int num;
	int mul;
};
struct LINK link[10000];

int cmp(const void*p,const void *q)
{
    struct LINK *w=(struct LINK*)p;
    struct LINK *e=(struct LINK*)q;
    if((w->mul)<(e->mul)) return 1;
    else return -1;
}

int main()
{
	int a[10000],b[10000],rel[10000],i=0,j=0,l=1,z,x,y=-1;
	char m;
	for(;;i++)
	{
		scanf("%d",&a[i]);
		m=getchar();
		if(m=='\n')
		break;
	}
	for(;;j++)
	{
		scanf("%d",&b[j]);
		m=getchar();
		if(m=='\n')
		break;
	}
	for(z=0;z<i;z+=2)
	{
		for(x=0;x<j;x+=2)
		{
			rel[y+1]=a[z]*b[x];rel[y+2]=a[z+1]+b[x+1];
			y+=2;
		}
	}
	j=0;
	for(i=0;i<y;i+=2)
	{
		link[j].num=rel[i];link[j].mul=rel[i+1];j++;
	}
	for(i=0;i<j;i++)
	{
		for(z=i+1;z<j;z++)
		{
			if(link[i].mul==link[z].mul)
			{
				link[i].num=link[i].num+link[z].num;
				for(x=z;x<j-1;x++)
					link[x]=link[x+1];
				j--;
			}
		}
	}
	qsort(link,j,sizeof(link[1]),cmp);
	for(i=0;i<j;i++)
	printf("%d %d ",link[i].num,link[i].mul);
}



