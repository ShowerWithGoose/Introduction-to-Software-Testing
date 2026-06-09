#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cmp( const void *p1, const void *p2 );
struct link{
	int an;
	int index;
	struct link *next;
}; 
struct out{
	int an;
	int xn;
};
int main()
{
	struct link *m=NULL,*n=NULL,*q,*p;
	struct out output[10000]; 
	int a,b,t=0,r=0,i,j,o;
	char c;
	do{
		scanf("%d %d",&a,&b);
		t++;
		q=(struct link*)malloc(sizeof(struct link));
		q->an=a;
		q->index=b; 
  		q->next = NULL;
  		if(m== NULL)
    	m = p = q;
    	else {
    	p->next = q;  
    	p = p->next;
		} 
		c=getchar();  
	}while(c!='\n');
	p->next=m; 
	do{
		scanf("%d %d",&a,&b);
		r++;
		q=(struct link*)malloc(sizeof(struct link));
		q->an=a;
		q->index=b; 
  		q->next = NULL;
  		if(n== NULL)
    	n = p = q;
    	else {
    	p->next = q;  
    	p = p->next;
		} 
		c=getchar();  
	}while(c!='\n');
	p=n;
	q=m;
	for(i=0,o=0;i<r;i++)
	{
		for(j=0;j<t;j++)
		{
			output[o].an=(p->an)*(q->an);
			output[o].xn=(p->index)+(q->index);
			q=q->next;
			o++;
		}
		p=p->next;
	}
	qsort(output,o,sizeof(output[0]),cmp);	
	for(i=0;i<o-1;i++)
	{
		if(output[i].xn==output[i+1].xn)
		{
			output[i+1].an+=output[i].an;
			output[i].xn=-1;
		}
	}
	qsort(output,o,sizeof(output[0]),cmp);
	for(i=0;i<o&&output[i].xn>=0;i++)
	{
		printf("%d %d ",output[i].an,output[i].xn);
	}													
	return 0;
}
int cmp( const void *p1, const void *p2 )
{
	struct out *c=(struct out*)p1;
	struct out *d=(struct out*)p2;
	if((c->xn)>(d->xn)) return -1;
	else return 1;
}

