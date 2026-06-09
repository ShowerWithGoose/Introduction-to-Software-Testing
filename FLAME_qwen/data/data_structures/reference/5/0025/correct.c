#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h, i=0, j, k, l, p[200], q[200];
char e=0;

typedef struct duoxiangshi
{
	int m;
	int n;
}dxs;

int compare(const void* a, const void*b){
	dxs* ia = (dxs*)a; 
	dxs* ib = (dxs*)b; 
	if(ia->n < ib->n || (ia->n == ib->n && ia->m > ib->m) ){
		return 1;
	}else{
		return -1;
	}
}

int main()
{
	dxs x[200];
	dxs y[200];
	dxs z[200];
	
	while(e != '\n')
	{
		scanf("%d%d", &x[i].m, &x[i].n);
		i++;
		e=getc(stdin);
	}
	j=i;
	
	i=0;
	e=0;
	
	while(e != '\n')
	{
		scanf("%d%d", &y[i].m, &y[i].n);
		i++;
		e=getc(stdin);
	}
	k=i;
	
	/*j=i;
	for(i=0;i<=j;i++)
	{
		printf("%d %d %d %d\n", x[i].a ,x[i].n ,y[i].a ,y[i].n );
	}*/
	
	for(i=0;i<j;i++)
	{
		for(h=0;h<k;h++)
		{
			z[l].m =x[i].m *y[h].m ;
			z[l].n =x[i].n +y[h].n ;
			l++;
		}
	}
	
	qsort(z, l, sizeof(z[0]), compare);
	
	h=0;
	for(i=0;i<l;i++)
	{
		if(z[i].n == z[i+1].n )
		{
			if(z[i].n == z[i+2].n )
			{
				p[h]=z[i].m +z[i+1].m +z[i+2].m ;
				q[h]=z[i].n ;
				h++;
				i += 2;
			}
			else
			{
			p[h]=z[i].m +z[i+1].m ;
			q[h]=z[i].n ;
			h++;
			i++;
			}
		}
		else
		{
			p[h]=z[i].m ;
			q[h]=z[i].n ;
			h++;
		}
	}
	
	for(i=0;i<h;i++)
	{
		printf("%d %d ", p[i], q[i]);
	}
	
	return 0;
}



