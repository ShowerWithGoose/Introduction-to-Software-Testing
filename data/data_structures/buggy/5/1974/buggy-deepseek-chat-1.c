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
     return c->xi-d->xi; // @@ The comparison function should sort in descending order of exponents, but this sorts in ascending order (c->xi - d->xi gives ascending). For descending, use d->xi - c->xi.
    
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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ This loop reads the second polynomial incorrectly. It does not read the newline character, so it may read extra data or fail to terminate properly. The input format for the second polynomial is the same as the first (ending with newline), so it should use the same pattern as the first while loop.

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ When i is 0, result[i-1] accesses out-of-bounds memory. The condition i>0 should be checked before accessing result[i-1].
        result[i-1].num=result[i].num+result[i-1].num;
        i--; // @@ This decrement of i inside the loop causes the loop to skip the next element, potentially missing terms or causing incorrect merging.
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Similar out-of-bounds issue when i is 0, accessing result[i-1] is invalid.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}