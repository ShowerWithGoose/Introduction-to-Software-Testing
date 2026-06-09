#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

struct line {
    int x,y,x1,y1;
};
int main() {
    int n,i,j;
    struct line line1[100];
    struct line k; 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line1[i].x,&line1[i].y,&line1[i].x1,&line1[i].y1);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(line1[i].x1>line1[j].x1){
                k=line1[i];
                line1[i]=line1[j];
                line1[j]=k;
            }
        }
    }
    int count=1,countmax=0,firstx,firsty,x0,y0;
    for(i=n-1;i>=0;i--){
    	x0=line1[i].x;
    	y0=line1[i].y;
    	count=1;
		for(j=i-1;j>=0;j--){
            if((line1[j].x1==x0)&&(line1[j].y1==y0)){
                count++;
                if(count>countmax){
                    countmax=count;
                    firstx=line1[j].x;
                    firsty=line1[j].y;
                }
                x0=line1[j].x;
                y0=line1[j].y;
                
            }
            
        }

    }
    printf("%d %d %d",countmax,firstx,firsty);


    return 0;
}



