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
        for(int i=0;i<n;i++)printf("%d",b[i]); // @@ [Missing space between numbers as required by output format; should be printf("%d ", b[i]);]
        printf("\n");
        
    }
    else{
        for(j;j<n;j++){ // @@ [Initialization of j is missing in the loop; should be for(j=0; j<n; j++) or declare and initialize properly. As written, j starts from its current value (0), but this style is error-prone and non-standard. However, the real issue is that 'j' is not reset to 0 on subsequent calls due to being declared outside the loop. But since j=0 is set at function entry, it may work. The bigger issue is output formatting.]
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