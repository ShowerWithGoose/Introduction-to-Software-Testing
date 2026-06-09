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
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){ // @@ [The second polynomial should be read in the same format as the first, using a character to detect newline. Using EOF will cause the program to wait indefinitely or read beyond the intended input.]

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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ [The combination logic is flawed: modifying result[i-1] and then manually decrementing i causes adjacent terms to be skipped or processed incorrectly. This leads to missing or duplicate output.]
        result[i-1].num=result[i].num+result[i-1].num; // @@ [Part of the flawed combining sequence.]
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ [The conditional printing logic is incorrect; it prints only when exponents differ from the previous term, but due to the earlier i-- modifications, the order and selection of printed terms become unpredictable.]
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){ // @@ [Printing the last term separately assumes that the loop reaches i==0 correctly, but the combination logic may skip terms or alter indices, leading to incomplete output.]
     pf("%d %d",result[i].num,result[i].xi);
 }
}



    return 0;
}