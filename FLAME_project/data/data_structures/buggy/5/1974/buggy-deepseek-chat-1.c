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
     return c->xi-d->xi; // @@ The comparison function returns the difference of exponents, but for descending order (higher exponent first) it should return d->xi - c->xi. Also, the function should return an int, but the difference may overflow; however, the main issue is the order direction.
    
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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ This loop reads the second polynomial incorrectly. It does not handle the newline termination properly and may read extra data or fail to stop. The input format ends with a newline, not EOF. Also, it does not check for the newline character after each pair, so it may read beyond the intended input.

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ This line has an out-of-bounds access when i=0, because result[i-1] accesses result[-1]. The condition i>0 is checked, but the expression result[i-1] is evaluated before the check, causing undefined behavior. Also, the logic for combining like terms is flawed: it modifies result[i-1] and then decrements i, but the loop continues, potentially skipping terms or incorrectly combining.
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Similar out-of-bounds issue: when i=0, result[i-1] is invalid. Also, the condition for printing is incorrect; it prints only when exponents differ, but the last term (i=0) is handled separately, which may cause missing terms or incorrect output order.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}