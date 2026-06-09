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
     return c->xi-d->xi; // @@ The comparison function returns the difference of exponents, but for descending order (as required by the problem), it should return d->xi - c->xi. Also, the function should return 0 when equal to avoid undefined behavior in qsort.
    
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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ This loop reads the second polynomial incorrectly. It does not handle the newline termination properly and may read extra data or fail to stop. The input format ends with a newline, not EOF, so this loop may not terminate correctly.

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ This line accesses result[i-1] when i=0, causing out-of-bounds access. Also, the logic for combining like terms is flawed: it modifies result[i-1] and decrements i, but does not properly handle multiple consecutive equal exponents or remove the duplicate entry.
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ This condition also accesses result[i-1] when i=0, causing out-of-bounds access. Additionally, the logic for printing is incorrect because it skips terms when exponents are equal and does not handle the case where the last term has a duplicate exponent properly.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}