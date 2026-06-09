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
    while(num[k]==0){ // @@ This loop may go out of bounds if all numbers become zero; should be bounded by i.
        k++;
    }
    sum+=num[k]; // @@ Incorrectly assumes the first non-zero number contributes with positive sign, ignoring the effect of any leading subtraction operator.
    char temc;
    for(int l=k;l<i;l++){ // @@ Loop should start at 0, not k, to process all operators; skipping initial operators loses their effect (e.g., "0 - 5" becomes 5 instead of -5).
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ The use of tem[l+1] to decide whether to add/subtract num[l+1] is logically inconsistent with the meaning of the tem array (which marks operators, not numbers).
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}