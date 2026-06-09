#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ The format string "%d %c" consumes whitespace but fails to handle multiple spaces or specific tokenization robustly for expressions like "10 + 20". More critically, it reads the operator into str[i] corresponding to the number index i. This mapping is fragile.
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ strlen on str is incorrect because str contains operators mixed with potential garbage or uninitialized data if not null-terminated properly, and the logic assumes str[i] holds the operator AFTER num[i]. However, the loop structure `scanf("%d %c")` puts the operator in str[i]. The length m will be the number of operators read.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ When i=0, str[-1] is accessed, which is out of bounds and undefined behavior. This causes unpredictable results.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ Similarly, when i=0, str[-1] is accessed. Also, integer division order is wrong: num[i]/num1[i-1] should be num1[i-1]/num[i] if num1[i-1] holds the left operand.
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ This is a comparison '==', not an assignment '='. It does not change the value of str[i].
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ This is a comparison '==', not an assignment '='. It does not change the value of str[i].
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ Sum is reset to num1[0] in every iteration of the loop. It should be initialized once before the loop.
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){
            printf("%d",sum);
        }
    }
    return 0;
}