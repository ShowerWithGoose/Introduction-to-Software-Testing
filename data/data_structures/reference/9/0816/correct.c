#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct node{
	int x1,y1,x2,y2;
    int flag;	
};
struct node line[100];
int cmp(const void*p,const void*q)
{
	struct node*a=(struct node*)p;
	struct node*b=(struct node*)q;
	return a->x1-b->x1;
}
int main()
{
	int n,i,j,k,test;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1 ,&line[i].y1 ,&line[i].x2 ,&line[i].y2 );
		
	}
	for(i=0;i<n;i++)
	line[i].flag =1;
    qsort(line,n,sizeof(struct node),cmp); 


    	for(i=0,j=i;i<n,j<n;j++)
    	{
    		test=0;
    		for(k=j+1;k<n;k++)
    		{
			   
			
    		if((line[j].x2==line[k].x1 &&line[j].y2 ==line[k].y1 )||(line[j].x2 ==line[k].x2 &&line[j].y2 ==line[k].y2 )||(line[j].x1==line[k].x2 &&line[j].y1 ==line[k].y2)||(line[j].x1==line[k].x1 &&line[j].y1 ==line[k].y1))
    		{
    			line[i].flag++;
    			j=k-1;
    			test=1;
    			
    			
			}
			if(test==1)
			break;
		}
		if(test==0)
		{
	        j=i;
			i++;	
		
		}
		}

	
	int max=line[0].flag ,MAX=0;
	for(i=0;i<n;i++)
	{
		if(line[i].flag>max)
	{
			max=line[i].flag ;
		MAX=i;}
	}
	printf("%d %d %d",max,line[MAX].x1 ,line[MAX].y1 );
	return 0;
}



