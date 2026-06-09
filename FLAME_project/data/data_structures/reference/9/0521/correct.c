#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct 
{
	int x1;
	int x2;
	int y1;
	int y2;
	int num;
}line;
line li[105];
/*¶¨ÒåÅÅĞòº¯Êı*/
int cmp(const void *a,const void *b){
    line c = *(line*)a;
    line d = *(line*)b;
    if(c.x1>d.x1)
	     return 1;
    else
    	return -1;
}

int main(int argc, char *argv[]) {
	int n=0,i=0,k=0,a1=0,a2=0,b1=0,b2=0,j=0,num0=0,x0=0,y0=0;
	scanf("%d",&n);
	while(i<n)
	{   
		scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
		li[i].x1=a1,li[i].x2=a2,li[i].y1=b1,li[i].y2=b2,li[i].num=1;	
		i++;
	}
	qsort(li,n,sizeof(li[0]),cmp);
	
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(li[j].x1==li[i].x2&&li[j].y1==li[i].y2)
			{
				li[i].x2=li[j].x2,li[i].y2=li[j].y2;
				li[i].num++;
			}
		}
	
	for(j=0;j<n;j++)
	{
		if(li[j].num>num0)
		{
			num0=li[j].num;
			x0=li[j].x1;
			y0=li[j].y1;
		}
	}
	printf("%d %d %d\n",num0,x0,y0);
	return 0;
}

