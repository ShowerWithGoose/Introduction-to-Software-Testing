#include<stdio.h>
int main(){
    char c[1000]="\0"; // @@ [Unused variable 'c'; not causing compilation error but indicates flawed design]
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]);
        while(sign[j]==' '){
            scanf("%c",&sign[j]); // @@ [This loop may cause infinite loop or undefined behavior if input ends without '=' because it keeps reading without checking for EOF or '=' inside the loop]
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
                num[m+1]=num[m]/num[m+1]; // @@ [Potential division by zero if num[m+1] is 0; also, integer division is required but using long long is okay, however logic flaw in handling operator precedence across entire expression]
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){
        k++; // @@ [If all num entries are zero (e.g., expression like "0*5="), this may go out of bounds leading to undefined behavior]
    }
    sum+=num[k];
    char temc;
    for(int l=k;l<i;l++){
        if(sign[l]=='+'){
            temc='+'; // @@ [Uninitialized use of 'temc' possible if first relevant operator isn't '+' or '-', leading to undefined behavior]
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ [Array index 'l+1' may exceed bounds when l == i-1 since tem has size 100 but accessed up to i which can be near 100]
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}