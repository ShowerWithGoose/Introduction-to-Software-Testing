#include<stdio.h>
int main(){
    char c[1000]="\0"; // @@ [Unused variable 'c'; not causing compilation error but indicates flawed logic]
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]); // @@ [Reading a single char may read whitespace; subsequent loop tries to skip spaces but doesn't handle all cases correctly, leading to potential misalignment between numbers and operators]
        while(sign[j]==' '){
            scanf("%c",&sign[j]); // @@ [This inner loop can cause infinite loop if input ends without '=' or if non-space follows; also, it overwrites sign[j] without advancing index properly]
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
                num[m+1]=num[m]/num[m+1]; // @@ [Potential division by zero if num[m+1] is 0; also, integer division is required but using long long may not match expected int behavior per problem]
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){
        k++; // @@ [If all num entries are zero (e.g., expression like "0+0="), this loop runs past array bounds causing undefined behavior]
    }
    sum+=num[k];
    char temc; // @@ [Uninitialized variable 'temc' used in comparisons later; leads to undefined behavior]
    for(int l=k;l<i;l++){
        if(sign[l]=='+'){
            temc='+';
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ [Accessing tem[l+1] where l can be up to i-1, so l+1 may exceed array bounds of 'tem']
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){ // @@ [Same out-of-bounds access as above; also logic fails to handle operator precedence correctly after marking terms with 'tem']
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}