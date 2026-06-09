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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ [This line incorrectly combines terms. After combining into result[i-1] and decrementing i, the loop will skip the combined term due to the for-loop's i--, and the term may never be printed. Also it does not handle the case where after combination the new result[i-1] might equal the next term.]
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ [This condition may fail to print the combined term. For example, after combining two equal exponents at indices i and i-1, i is decremented, so i now points to the combined term, but the loop's i-- will skip it, and this condition will not be checked correctly.]
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){ // @@ [This only prints when i==0, but due to earlier decrements, the loop may end with i < 0, causing the last combined term to never be printed.]
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}