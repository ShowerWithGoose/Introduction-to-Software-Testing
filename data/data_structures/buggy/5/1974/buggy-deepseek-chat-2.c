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
     return c->xi-d->xi; // @@ The comparison function should sort in descending order of exponents, but this sorts in ascending order. Also, the return value may overflow for large differences.
    
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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ This loop reads the second polynomial incorrectly. It does not read the newline character, so it may read beyond the intended input or fail to terminate properly. The input format requires reading until a newline, not EOF.

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ This line accesses result[i-1] when i=0, causing out-of-bounds access. The condition i>0 should be checked before accessing result[i-1].
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Same issue: accessing result[i-1] when i=0 is out-of-bounds. Also, the logic for combining like terms is flawed; it only combines adjacent terms after sorting, but the decrement of i may skip terms.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}