#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ [Format %c does not skip whitespace; if input contains spaces, it may read a space instead of the operator. Use " %c" to skip whitespace.]
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [str is not null-terminated; strlen results in undefined behavior. Should use the actual count of elements (i+1).]
    for(i=0;i<m;i++){ // @@ [Loop bound m is unreliable due to strlen error; also causes out-of-range access later.]
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [When i=0, str[-1] is out of bounds. Loop should start at i=1.]
            num1[i]=num1[i-1]*num[i]; // @@ [Incorrect precedence handling; num1[i-1] may be zero from previous operations, and the left operand is not preserved correctly.]
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same out-of-bounds issue for division.]
            num1[i]=num[i]/num1[i-1]; // @@ [Division operation uses num1[i-1] as divisor, which may be zero; also order of operands is reversed (should be num[i-1]/num[i] for left-to-right evaluation).]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){ // @@ [Uses unreliable m again.]
        if(str[0]=='*'||str[0]=='/'){ // @@ [Incorrect logic: unconditionally overwriting the first operator disregards expression validity.]
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ [Logic for converting * and / based on previous operator is flawed; changes operator semantics incorrectly.]
                str[i]=='+'; // @@ [Comparison instead of assignment; should be str[i]='+'.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ [Same flawed logic.]
                str[i]=='-'; // @@ [Comparison instead of assignment; should be str[i]='-'.]
            }
        }
    }
    for(i=1;i<m;i++){ // @@ [Uses unreliable m again; loop may iterate over uninitialized values.]
        sum=num1[0]; // @@ [sum is reinitialized every iteration, discarding previous accumulation. Should be set once before the loop.]
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