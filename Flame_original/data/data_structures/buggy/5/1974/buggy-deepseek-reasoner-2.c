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
     return c->xi-d->xi;
    
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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ Error: second polynomial input should detect newline, not EOF; using EOF may cause infinite loop or incorrect reading.

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ Error: accessing result[i-1] when i=0 is guarded, but the logic for merging like terms is flawed; modifying loop variable inside will skip indices.
        result[i-1].num=result[i].num+result[i-1].num;
        i--; // @@ Error: modifying loop variable inside the for loop causes incorrect iteration and may skip merging of additional like terms.
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Error: prints terms without checking if coefficient is zero; also may print indices that were already merged/skipped.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){ // @@ Error: prints last term without checking zero coefficient; only one term may remain but could have coefficient zero after cancellation.
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}