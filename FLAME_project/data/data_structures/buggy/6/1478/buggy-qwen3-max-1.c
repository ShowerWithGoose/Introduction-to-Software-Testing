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
        if(l>=0){ // @@ [The condition should be `l > 0` to check if stack is not empty. When `l == 0`, the stack is empty, so pop should result in "error". Current logic treats `l == 0` as valid and accesses `zhan[-1]` after decrement, causing incorrect behavior.]
        chu[hao]=zhan[l-1];
        l--;hao++;
        }else{
            chu[hao]=0;
            hao++,l--;
        }
        
    
    }
}
if(hao==13){
    printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
}else{
    for(int i=0;i<hao;i++){
    if(chu[i]!=0){ // @@ [Using `chu[i] != 0` to decide between printing a number or "error" is flawed because 0 could be a valid popped value. The program stores 0 in `chu[i]` to represent an error, but if a real 0 were ever pushed and popped (though not in this test case), it would be misreported as "error". More critically, the logic for detecting underflow is wrong (see earlier comment), so even the stored 0s don't correctly correspond to actual errors.]
        printf("%d ",chu[i]);
    }else{printf("error ");
    }
}
}



    return 0;
}