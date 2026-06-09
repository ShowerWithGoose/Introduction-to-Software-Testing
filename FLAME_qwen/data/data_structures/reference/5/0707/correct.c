#include <stdio.h> 
#include <stdlib.h> 
struct multinomial
{
	int a;
	int b;
}x[2000],y[2000],z[2000];

int cmp(const void*p1,const void*p2)
{
	struct multinomial *p=(struct multinomial*)p1;
	struct multinomial *q=(struct multinomial*)p2;
	return q->b-p->b;
}


int main()
{int i=0,j=0,m,n,k=0;
	char c;
do
{scanf("%d%d%c",&x[i].a,&x[i].b,&c);
i++;
}while(c!='\n');

do
{scanf("%d%d%c",&y[j].a,&y[j].b,&c);
j++;
}while(c!='\n');

for(m=0;m<i;m++)
for(n=0;n<j;n++)
{z[k].a=x[m].a*y[n].a;
z[k].b=x[m].b+y[n].b;
k++;
	}	
	
	qsort(z,k,8,cmp);
	
	for(i=0;i<k;i++)
	{if(z[i].b==z[i+1].b&&z[i].b!=0)
	{z[i+1].a+=z[i].a;
			z[i].a=0;
	}
	}

	qsort(z,k,8,cmp);
	for(i=0;i<k;i++)
	{
		if(z[i].a==0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",z[i].a,z[i].b);
		}
	}
	return 0;
}



