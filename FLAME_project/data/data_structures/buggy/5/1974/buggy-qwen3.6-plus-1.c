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
     return c->xi-d->xi; // @@ The comparison function sorts in ascending order, but the output loop iterates backwards. While this logic can work for descending output, it fails to handle the case where coefficients sum to zero correctly if not filtered, and more importantly, the merging logic below is flawed. However, the primary logical error causing the Wrong Answer is in the merging/output loop.
    
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

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ This condition accesses result[i-1] when i=0 is prevented by i>0, but the logic for merging coefficients is incorrect. It modifies result[i-1] and then decrements i. If multiple terms have the same exponent, this simple pairwise merge might miss accumulations or handle them incorrectly depending on sort stability and grouping. More critically, it does not check if the resulting coefficient is zero.
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ This print condition is flawed. It prints result[i] only if it's different from the previous one (in the sorted array, which is next one in descending iteration). It skips printing if it was merged. However, the last element (i=0) is handled separately. The main issue is that if a coefficient becomes 0 after addition, it should not be printed. The problem states "Only terms with non-zero coefficients will appear in the input", implying output should also likely filter zero coefficients or the standard polynomial representation omits them. The expected output shows `157 26` while buggy shows `12 26` and `468 24` etc wait, let's look at the specific difference.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi); // @@ This prints the last term regardless of whether its coefficient is zero. Also, if the previous term was merged into this one, this prints the accumulated value. But the merging logic above is suspect. Let's re-evaluate the merging.
 }
}



    return 0;
}