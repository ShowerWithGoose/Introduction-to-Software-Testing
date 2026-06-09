#include<stdio.h>
#include<string.h>
struct line{
	int x1,y1,x2,y2;
}a[100],t;
int n,i,j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d %d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i].x1>a[j].x1){
			  t=a[i];
			  a[i]=a[j];
			  a[j]=t;
			}//排序
    int number,max=1,max_x1=0,max_y1=0;
	for(i=1;i<=n;i++){
    	number=1; 
	    for(j=i+1;j<=n;j++){
			if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1){
    			a[i].x2=a[j].x2;
    			a[i].y2=a[j].y2;
    			number++;
			}//连成一条线 
		}
		if(number>=max){
			max=number;
			max_x1=a[i].x1;
			max_y1=a[i].y1;	
			} 
	}
    printf("%d %d %d",max,max_x1,max_y1);
    	
    		
			
		
	
	
	return 0;
}

