#include<stdio.h>
int main(){
    char c[1000]="\0"; // @@ [Unused variable 'c'; not causing compilation error but indicates flawed design]
    long long num[100];
    int tem[100]={0};
    char sign[100];
    int i=0,j=0;
    while(1){  
        scanf("%lld",&num[i]);
        scanf("%c",&sign[j]); // @@ [This reads a single char including whitespace; the following loop tries to skip spaces but may cause issues if input ends unexpectedly]
        while(sign[j]==' '){
            scanf("%c",&sign[j]); // @@ [If the next character after number is '=', this loop won't run, which is okay, but if there are multiple spaces, it consumes them correctly. However, potential issue: if input ends before '=', undefined behavior possible]
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
                num[m+1]=num[m]*num[m+1]; // @@ [Accesses num[m+1] which may be uninitialized if expression ends abruptly; but per problem statement expression is valid so maybe safe]
                num[m]=0;
            }
            else{
                num[m+1]=num[m]/num[m+1]; // @@ [Same as above; also integer division is required and this does integer division for long long, which is okay]
                num[m]=0;
            }
            tem[m]=1;
        }
    }
    long long sum=0;
    int k=0;
    while(num[k]==0){ // @@ [If all leading numbers become zero due to multiplication/division handling, this may go out of bounds; also skips necessary zeros that are actual values]
        k++;
    }
    sum+=num[k];
    char temc; // @@ [Uninitialized variable 'temc' used in comparisons later; leads to undefined behavior]
    for(int l=k;l<i;l++){
        if(sign[l]=='+'){
            temc='+'; // @@ [Only sets temc on '+' or '-', but if first relevant operator isn't hit, temc remains uninitialized]
        }
        if(sign[l]=='-'){
            temc='-';
        }
        if(temc=='+'&&tem[l+1]==0){ // @@ [Uses uninitialized 'temc' if no '+' or '-' encountered yet; also logic flawed: should process operators sequentially, not based on tem array]
            sum+=num[l+1];
        }
        else if(temc=='-'&&tem[l+1]==0){
            sum-=num[l+1];
        }
    }
    printf("%lld",sum);
    return 0;
}