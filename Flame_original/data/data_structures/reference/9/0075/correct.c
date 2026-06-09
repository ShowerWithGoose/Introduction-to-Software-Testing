#include<stdio.h>

struct po{
   int  x1;
    int x2;
    int y1;
    int y2;
};

int main()

{ struct po line[100];
    int n;
    int i,j;
    scanf("%d",&n);
    
    for (i=0; i<n; i++) {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    
    struct po too;
    for (i=0;i<n;i++){
        for (j=i+1; j<n; j++) {
            if (line[i].x1>line[j].x1) {
                too=line[j];
                line[j]=line[i];
                line[i]=too;
                
                
            }
        }
    }
    
    int max=1,max1=0,max2=0;
    
    for (i=0; i<n; i++) {
        int x2,y2,all=1;
        x2=line[i].x2;
        y2=line[i].y2;
        
        for (j=i+1; j<n; j++) {
            if (line[j].x1==x2&&line[j].y1==y2) {
                all++;
                x2=line[j].x2;
                y2=line[j].y2;
                
            }
            if (all>max) {
                max=all;
                max1=line[i].x1;
                max2=line[i].y1;
            }
            
        }
        
        
        
        
    }
    
    
    
    
    
    
    printf("%d %d %d\n",max,max1,max2);
    
    
    
    
    
    return 0;
}

