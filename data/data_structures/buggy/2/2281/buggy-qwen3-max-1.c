#include<stdio.h>
int main(){
    char c[1000]="\0"; // @@ [Unused variable 'c'; not causing compilation error but indicates flawed design]
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]); // @@ [Reading a single char may read whitespace; subsequent loop tries to skip spaces but logic is flawed and may cause infinite loop or undefined behavior]
        while(sign[j]==' '){
            scanf("%c",&sign[j]); // @@ [If input ends without '=', this loop may block indefinitely or read past intended input; also, no check for EOF]
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
                num[m+1]=num[m]*num[m+1]; // @@ [Accessing num[m+1] assumes it exists; but if expression ends with operator before '=', this leads to out-of-bounds read/write]
                num[m]=0;
            }
            else{
                num[m+1]=num[m]/num[m+1]; // @@ [Same as above: potential out-of-bounds access; also division by zero not handled per problem (though problem says valid input)]
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){ // @@ [If all numbers become zero due to multiplication/division handling, this may go out of bounds (k exceeds array limit)]
        k++;
    }
    sum+=num[k];
    char temc; // @@ [Uninitialized variable 'temc' used in comparisons later; leads to undefined behavior]
    for(int l=k;l<i;l++){ // @@ [Loop condition uses 'i' which is count of numbers minus one, but indexing may mismatch due to prior modifications]
        if(sign[l]=='+'){
            temc='+'; // @@ ['temc' only set when '+' or '-' encountered, but if first relevant operator is missing, remains uninitialized]
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ [Accessing tem[l+1] may be out of bounds; l goes up to i-1, so l+1 can be i, but tem size is 100 and i may approach 100]
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){ // @@ [Same out-of-bounds risk for tem[l+1]; also logic fails to handle sequences like "5 * 2 + 3" correctly due to zeroing and skipping]
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}