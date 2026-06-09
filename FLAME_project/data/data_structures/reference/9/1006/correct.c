#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    struct line{
        int x0,y0,x,y,lth,flag;
    }p[110];
    
    int n,i,j,mlth=0,mnum;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&p[i].x0,&p[i].y0,&p[i].x,&p[i].y);
        p[i].lth=1;
        p[i].flag=1;
    }

    for(i=0;i<n;i++){
        if(p[i].flag){
            for(j=0;j<n;j++){
                if(j==i||p[j].flag==0){
                    j++;
                }

                if(p[j].x0==p[i].x&&p[j].y0==p[i].y){
                    p[i].x=p[j].x;
                    p[i].y=p[j].y;
                    p[i].lth+=p[j].lth;
                    p[j].flag=0;
                    j=-1;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        if(p[i].flag){
            if(mlth<p[i].lth){
                mlth=p[i].lth;
                mnum=i;
            }
        }
    }

    printf("%d %d %d",p[mnum].lth,p[mnum].x0,p[mnum].y0);

    return 0;
}
