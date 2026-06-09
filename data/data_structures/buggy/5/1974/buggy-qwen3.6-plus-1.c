#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
typedef struct {
    int num;
    int xi;
}number;
 number cheng[500];
 number cheng1[500];
 number result[50000];
int compare(const void *a,const void *b){
     number *c=(number *)a;
     number *d=(number *)b;
     return c->xi-d->xi; // @@ Sorts exponents in ascending order, but the problem requires descending order. Should be `d->xi - c->xi`.
    
}

int main(){

int a,b,c=0,d,i=0,j=0;


char k;

while(1){
    sf("%d%d%c",&cheng[i].num,&cheng[i].xi,&k);
    i++;
    if(k=='\n')
    break;

}
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ The input format specifies the polynomial ends with a newline, not EOF. This loop may fail to terminate correctly or read trailing whitespace. Should check for newline like the first loop.

    j++;

}
for(a=0;a<i;a++){
    for(b=0;b<j;b++){
result[c].num=cheng[a].num*cheng1[b].num;
result[c].xi=cheng[a].xi+cheng1[b].xi;
c++;
    }
}
qsort(result,c,sizeof(result[0]),compare);
for(i=c-1;i>=0;i--){ 

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ Accesses `result[i-1]` before checking `i>0`, causing out-of-bounds array access when `i=0`. The condition `i>0` must be evaluated first due to left-to-right evaluation of `&&`.
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Same out-of-bounds access issue when `i=0`. Additionally, the logic incorrectly skips printing terms that don't have a following term with a different exponent, and fails to check for zero coefficients after merging.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi); // @@ Does not check if the coefficient is zero. If all terms cancel out after addition, it will incorrectly print "0 0".
 }
}



    return 0;
}