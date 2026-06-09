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
        if(l < 100) { // @@ [The original code did not check for stack overflow (capacity 100). If the stack is full, it should output "error" instead of pushing.]
            zhan[l]=ru[i][1];
            l++;
        } else {
            chu[hao] = 0; // Mark as error
            hao++;
        }
    }else if(ru[i][0]==0){
        if(l > 0){ // @@ [The original condition `l>=0` is incorrect. If l==0, the stack is empty, so accessing zhan[l-1] is invalid and should result in an error. It must be `l > 0` to ensure there is an element to pop.]
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0;
            hao++; // @@ [The original code had `l--` here, which would make `l` negative. `l` represents the stack size and should not go below 0. Only `hao` (output index) should increment.]
        }
        
    
    }
}
// @@ [The hardcoded check `if(hao==13)` is incorrect and fragile. It assumes a specific test case length and outputs a fixed string, failing for any other input. This entire block should be removed or replaced with general logic.]
if(hao==13){
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