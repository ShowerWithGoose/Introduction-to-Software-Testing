#include<stdio.h>
int n,i,j,maxs=0,x,y;
struct Line{
	int x1,y1,x2,y2;
	int cout;
	//int x,y;
}a[105];
int cmp1(const void *pa,const void *pb);

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 {
	 	scanf("%d%d%d%d",&a[i].x1,
	          &a[i].y1,&a[i].x2,&a[i].y2);
	    a[i].cout=1;
	   // a[i].x=a[i].x2;
	   // a[i].y=a[i].y2;
	 }
	qsort(a,n,sizeof(struct Line),cmp1);
	/*for(i=0;i<n;i++)
	 printf("%d %d %d %d %d\n",a[i].x1,a[i].y1
	         ,a[i].x2,a[i].y2,a[i].cout);*/
	for(i=n-1;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		 {
		 	if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
		 	{
		 		a[j].cout=a[j].cout+a[i].cout;
		 	//	a[j].x=a[i].x;
		 	//	a[j].y=a[i].y;
		 	    break;
			 }
		 	
		 	if(a[i].x1>a[j].x2) break;
		 	else
		 	 {
		 	 	if(a[i].x1==a[j].x2&&a[i].y1>a[j].y2)
		 	 	 break;
		 	 	 
			  }
		 }
	}
	/*for(i=0;i<n;i++)
	 printf("%d %d %d %d %d\n",a[i].x1,a[i].y1
	         ,a[i].x2,a[i].y2,a[i].cout);*/
	for(i=0;i<n;i++)
	 if(a[i].cout>maxs)
	  {
	  	maxs=a[i].cout;
	  	x=a[i].x1;
	  	y=a[i].y1;
	  }
	printf("%d %d %d",maxs,x,y);
	return 0;
}

int cmp1(const void *pa,const void *pb)
 {
	struct Line a=*((struct Line *)pa);
 	struct Line b=*((struct Line *)pb);
 	
 	if(a.x2>b.x2) return 1;
 	else
 	 {
 	 	if(a.x2==b.x2) 
 	 	 {
 	 	 	if(a.y2>b.y2) return 1;
 	 	 	else return -1;
		   }
		else return -1;
	  }
	
 }

