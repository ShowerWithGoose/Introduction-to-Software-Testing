#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

struct line {
    int x1,y1,x2,y2;
};
int main() {
    int n,i,j;
    struct line a[100];
    struct line k; 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i].x2>a[j].x2){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    int count=1,countmax=0,x,y,p,q;
    for(i=n-1;i>=0;i--){
    	p=a[i].x1;
    	q=a[i].y1;
    	count=1;
		for(j=i-1;j>=0;j--){
            if((a[j].x2==p)&&(a[j].y2==q)){
                count++;
                if(count>countmax){
                    countmax=count;
                    x=a[j].x1;
                    y=a[j].y1;
                }
                p=a[j].x1;
                q=a[j].y1;
                
            }
            
        }

    }
    printf("%d %d %d",countmax,x,y);


    return 0;
}



