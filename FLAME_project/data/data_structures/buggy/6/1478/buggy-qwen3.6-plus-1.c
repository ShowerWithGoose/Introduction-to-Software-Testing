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
        if(l >= 100) { // @@ The problem states max capacity is 100. Need to check for stack overflow before pushing. If full, output "error". The current code just overwrites or ignores bounds.
             // However, the logic below needs to handle the "error" state for push as well. 
             // The current structure doesn't easily support printing error immediately for push without restructuring.
             // But looking at the expected output, push errors are not explicitly printed as "error" in the sequence unless specified? 
             // Wait, the problem says: "If a pop operation is attempted when the stack is empty, or if a push operation is attempted when the stack is full, output the string "error" followed by a space."
             // So push overflow should also print error.
             printf("error ");
        } else {
            zhan[l]=ru[i][1];
            l++;
        }
    }else if(ru[i][0]==0){
        if(l > 0){ // @@ Error: Condition `l>=0` is always true for unsigned-like logic or allows accessing zhan[-1] if l is 0. Should be `l > 0` to check if stack is not empty.
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0; // @@ Using 0 to represent error is ambiguous if 0 is a valid pushed value (though problem says pushed ints are not 0, -1, 1). But standard practice is to track error state separately or print immediately.
            hao++,l--; // @@ Error: `l--` makes `l` negative, which is invalid for stack pointer. Should keep `l` at 0.
        }
        
    
    }
}
if(hao==13){ // @@ Hardcoding output based on specific test case length is incorrect and fails for other inputs. This entire block is a hack.
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