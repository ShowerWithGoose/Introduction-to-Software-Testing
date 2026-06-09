#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]);
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ str is not null-terminated, strlen will read out of bounds causing undefined behavior
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ When i=0, str[-1] is accessed, causing out-of-bounds memory access
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ When i=0, str[-1] is accessed, causing out-of-bounds memory access
            num1[i]=num[i]/num1[i-1]; // @@ Division operands are reversed, should be num1[i-1] / num[i]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){ // @@ Incorrectly modifies the first operator to '+', breaking valid expressions
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ Uses comparison operator '==' instead of assignment '=', so the operator is never updated
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ Uses comparison operator '==' instead of assignment '=', so the operator is never updated
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ Resets sum to num1[0] in every iteration, losing previously accumulated results
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