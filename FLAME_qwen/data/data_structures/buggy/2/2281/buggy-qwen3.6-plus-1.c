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
                num[m]=0; // @@ [Using 0 to mark consumed numbers is flawed because 0 is a valid arithmetic result, causing the initial search loop to skip valid operands]
            }
            else{
                num[m+1]=num[m]/num[m+1];
                num[m]=0; // @@ [Using 0 to mark consumed numbers is flawed because 0 is a valid arithmetic result, causing the initial search loop to skip valid operands]
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){
        k++;
    }
    sum+=num[k];
    char temc; // @@ [Variable temc is uninitialized, leading to undefined behavior when evaluated in conditions before assignment]
    for(int l=k;l<i;l++){ // @@ [Loop bound l<i causes out-of-bounds access for num[l+1] and tem[l+1] when l=i-1, and incorrectly processes the '=' operator]
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ [Logic error: temc retains previous operator across * and /, and tem[l+1] index mismatch incorrectly checks operator status instead of number consumption]
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){ // @@ [Same logic error as above: incorrect operator state persistence and index mismatch for tem array]
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}