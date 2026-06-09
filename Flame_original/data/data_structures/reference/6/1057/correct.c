#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAXN 120
//define mst(s) memset(s,0,sizeof(s))
int a[MAXN];
int main(void)
{
    int i,j,k,n,m,op,num,tot=-1;
    //freopen("in.stack.txt","r",stdin);
    while(~scanf("%d",&op)){
        if(op==1){
            scanf("%d",&num);
            if(tot<99){
                tot++;
                a[tot]=num;
            }else{
                printf("error ");
            }
        }else if(op==0){
            if(tot==-1){
                printf("error ");
            }else{
                printf("%d ",a[tot]);
                a[tot]=0;
                tot--;
            }
        }else{
            break;
        }
    }
    


    
    return 0;
}
