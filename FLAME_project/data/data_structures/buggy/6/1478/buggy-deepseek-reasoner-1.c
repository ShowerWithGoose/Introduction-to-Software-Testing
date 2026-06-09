#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int ru[105][105],chu[105],zhan[105];
int main(){
        //scanf("  ",& );   printf("  ");   for(i=1;i<= ;i++)
int cao=0,n=0;
while(1){
    scanf("%d",&cao);
    ru[n][0]=cao;
    if(cao==1){
        scanf("%d",&ru[n][1]);
        
        n++;
    }else if(cao==0){
        ru[n][1]=0;
        n++;
    }else if(cao==-1){
        break;
    }
}

int l=0,hao=0;
for(int i=0;i<n;i++){
    if(ru[i][0]==1){
        zhan[l]=ru[i][1];
        l++;
    }else if(ru[i][0]==0){
        if(l>=0){ // @@ Error: Should be l>0. When l==0 stack is empty, but this condition is true, leading to invalid pop from empty stack (accessing zhan[-1]) and incorrect output.
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0;
            hao++,l--; // @@ Error: Decrements l even on failed pop, causing l to become negative. This corrupts the stack pointer and leads to subsequent operations incorrectly reporting errors.
        }
        
    
    }
}
if(hao==13){ // @@ Error: Hardcoded for a specific test case, not a general solution. Should be removed; the correct logic should handle all cases.
    printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
}else{
    for(int i=0;i<hao;i++){
    if(chu[i]!=0){
        printf("%d ",chu[i]);
    }else{printf("error ");
    }
}
}



    return 0;
}