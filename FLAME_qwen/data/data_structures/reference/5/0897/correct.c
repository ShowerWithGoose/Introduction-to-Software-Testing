#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node {
	int x;
	int y;
}a[10000],b[10000],p[10000];
	int ia = 0,ib= 0;
char c = ' ';
int cmp(const void *a, const void*b)             //排序，按指数从大到小排序
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->y - c->y;
}

int main()
{
    while( c != '\n')                                 
    {
        scanf("%d%d%c",&a[ia].x,&a[ia].y,&c);
        ia++;
    }
    c = ' ';
    while( c != '\n')                                
    {
        scanf("%d%d%c",&b[ib].x,&b[ib].y,&c);
        ib++;
    }
    int k = 0;
    for(int i = 0; i < ia; i++)                    
        for(int j = 0; j < ib; j++)
    {
        p[k].x = a[i].x*b[j].x;
        p[k].y = a[i].y + b[j].y;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp );
    for(int i=0;i<k-1;i++){
    	if(p[i].y==p[i+1].y&&p[i].x!=0){
    		p[i+1].x+=p[i].x;
    		p[i].x=0;
		}
	}
	for(int i=0;i<k;i++){
		if(p[i].x!=0){
			printf("%d %d ",p[i].x,p[i].y);
		}
	}
    
	return 0;
}

