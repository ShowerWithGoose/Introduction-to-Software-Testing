#include<stdio.h>
#include<string.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main(){
	struct line a[200];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	struct line temp;
    for(i=0; i<n; i++)
    for(j=i; j<n; j++){
        if(a[i].x1 > a[j].x1)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }	int max=1;int x,y;
    for(i=0;i<n;i++){
    
    	
    	int x2,y2,count=1;
    	x2=a[i].x2;
    	y2=a[i].y2;
    	for(j=i+1;j<n;j++){
    		if(x2==a[j].x1&&y2==a[j].y1){
    			count++;
    			x2=a[j].x2;
    			y2=a[j].y2;
    			
			}
		}
    	if(count>max){
    		max=count;
    		x=a[i].x1;
    		y=a[i].y1;
		}
		
	}
	printf("%d %d %d",max,x,y);
}

