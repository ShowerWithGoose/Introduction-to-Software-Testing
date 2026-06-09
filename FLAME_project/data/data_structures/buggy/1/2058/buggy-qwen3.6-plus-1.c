#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#define MAX(x,y) (((x)>(y))?(x) :(y))
#define MIN(x,y) (((x)<(y))?(x) :(y))
#define LL long long
#define eps 1e-9
#define DAXIE(c) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )
#define F(i,l,r) for(int i=(l);i<(r);i++)
#define CASE break;case
#define FD(i,l,r) for(int i=(l);i<=(r);i++)
int mark[10]={0},a[11],b[11];
void rank(int k,int n){
    int j=0;
    if(k==n){
        for(int i=0;i<n;i++)printf("%d",b[i]); // @@ The output format requires spaces between integers, but this line prints them consecutively without separators.
        printf("\n");
        
    }
    else{
        for(j;j<n;j++){
            if(mark[j]==0){
                b[k]=a[j];
                mark[j]=1;
                rank(k+1,n);
                mark[j]=0;
            }
        }
    }
}


int main(){
    int n,k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    rank(k,n);
    
    
    
    
    
    

    return 0;
}