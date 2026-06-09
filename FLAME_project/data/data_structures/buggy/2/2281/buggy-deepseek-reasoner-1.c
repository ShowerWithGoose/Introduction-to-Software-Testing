#include<stdio.h>
int main(){
    char c[1000]="\0";
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]); // @@ This line reads the next character after the number, which could be a space. If the expression is just "0 =", it reads the space first, then the while loop below overwrites sign[j] with '=', but the break occurs before incrementing i and j, leaving i=0, j=0. This causes later code to treat num[0] as the only number, but subsequent loops use uninitialized memory.
        while(sign[j]==' '){
            scanf("%c",&sign[j]); // @@ This loop correctly skips spaces but overwrites the same sign[j]. After reading the '=', the code breaks without incrementing i and j, so the operator count remains zero.
        }
        if(sign[j]=='='){
            break; // @@ Break occurs before incrementing i and j, so i and j remain 0. The program then fails to handle the case of a single number with no operators, leading to out-of-bounds access on num array.
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
    while(num[k]==0){ // @@ This loop assumes that num[k] is zero only for indices that have been zeroed out. However, for a single number "0", num[0]=0, so it increments k to 1 and accesses uninitialized num[1], which contains garbage. This leads to undefined behavior and wrong output.
        k++;
    }
    sum+=num[k]; // @@ Uses uninitialized num[k] (k=1) because the while loop skipped the only valid number. The sum becomes garbage.
    char temc;
    for(int l=k;l<i;l++){ // @@ i is 0, so l starts at 1 and the condition l<0 is false, so this loop never executes. Thus sum remains the uninitialized garbage value.
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}