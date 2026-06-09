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
int l=0,hao=0; // @@ In C89 standard, variable declarations must appear at the beginning of a block. Declaring variables after the while loop may cause a compilation error in strict C89 environments.
for(int i=0;i<n;i++){ // @@ Declaring the loop variable 'i' inside the for statement is a C99 feature. It will cause a compilation error in C89 mode.
    if(ru[i][0]==1){
        zhan[l]=ru[i][1]; // @@ Logical error: Missing check for stack full condition (maximum capacity 100). Should output "error " if the stack is full before pushing.
        l++;
    }else if(ru[i][0]==0){
        if(l>=0){ // @@ Logical error: The condition should be 'l>0'. When l==0, the stack is empty, and accessing zhan[l-1] results in out-of-bounds memory access.
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0;
            hao++,l--; // @@ Logical error: When popping from an empty stack, l should not be decremented. This corrupts the stack pointer state and leads to incorrect behavior.
        }
        
    
    }
}
if(hao==13){ // @@ Hardcoded output for a specific test case. This bypasses the actual logic and will fail on other inputs, violating the problem requirements.
    printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
}else{
    for(int i=0;i<hao;i++){ // @@ Declaring the loop variable 'i' inside the for statement is a C99 feature. It will cause a compilation error in C89 mode.
    if(chu[i]!=0){
        printf("%d ",chu[i]);
    }else{printf("error ");
    }
}
}



    return 0;
}