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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ scanf returns 0 when encountering a trailing newline without matching integers, causing an infinite loop; should check return value == 2 or read until newline

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ missing check for result[i].num != 0, may incorrectly print zero-coefficient terms after merging
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){ // @@ missing check for result[i].num != 0, may incorrectly print zero-coefficient terms
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}