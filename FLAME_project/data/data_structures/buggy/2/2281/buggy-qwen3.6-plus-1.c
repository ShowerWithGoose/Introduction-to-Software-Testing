#include<stdio.h>
int main(){
    char c[1000]="\0";
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]);
        while(sign[j]==' '){
            scanf("%c",&sign[j]);
        }
        if(sign[j]=='='){
            break;
        }
        i++;
        j++;
    }
    for(int m=0;m<j;m++){
        if(sign[m]=='*'||sign[m]=='/'){
            if(sign[m]=='*'){
                num[m+1]=num[m]*num[m+1];
                num[m]=0;
            }
            else{
                num[m+1]=num[m]/num[m+1];
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0 && k < i){ // @@ The original loop `while(num[k]==0)` does not check bounds, causing infinite loop or out-of-bounds access if all numbers are 0 or if the logic skips valid zeros incorrectly. Also, if the first number is 0, it skips it incorrectly.
        k++;
    }
    if (k >= i) { // @@ Need to handle case where k goes out of bounds, though logically k should point to a valid number if expression is valid. However, the logic below assumes k is valid.
         sum = 0; 
    } else {
         sum+=num[k];
    }
    char temc; // @@ Variable 'temc' is uninitialized. If the first relevant sign is not encountered before use in the loop, or if the loop starts at an index where temc hasn't been set by a previous iteration's sign check, it leads to undefined behavior. Specifically, if k > 0, the loop starts at l=k. The code checks sign[l] to set temc. But if the first operation to apply is at index k, temc is set inside the loop. However, the accumulation happens based on temc. Let's trace: l=k. sign[k] is read. temc is set. Then temc is used. This seems okay for the first step IF sign[k] is + or -. But what if sign[k] was * or /? It was marked in tem. The loop runs from k to i-1. Inside, it checks sign[l]. If sign[l] is * or /, temc is NOT updated. It retains previous value or garbage. This is a bug.
    for(int l=k;l<i;l++){
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ Accessing tem[l+1] and num[l+1] can go out of bounds when l == i-1. Also, logic relies on temc being correctly set. If sign[l] is * or /, temc is not updated, using stale/garbage value.
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}