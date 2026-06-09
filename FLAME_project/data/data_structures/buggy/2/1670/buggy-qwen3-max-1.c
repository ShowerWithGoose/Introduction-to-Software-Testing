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
    m=strlen(str); // @@ [strlen(str) is unreliable because str may not be null-terminated; also, the loop reads i+1 numbers but m is set to strlen(str), which equals i+1 due to the final '='. However, later loops use m as if it's the count of operators, causing off-by-one mismatches.]
    for(i=0;i<m;i++){
        num1[i]=num[i]; // @@ [This copies num[i] but doesn't handle the last number (after '=') correctly. The array num has i+1 elements (indices 0..i), but this loop only processes up to m-1 = i, missing the last operand in some logic paths.]
        if(str[i-1]=='*'){ // @@ [On the first iteration (i=0), str[-1] is accessed, which is undefined behavior. This leads to incorrect or unpredictable results.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same issue: accessing str[-1] when i=0 causes undefined behavior. Also, division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1].]
            num1[i]=num[i]/num1[i-1]; // @@ [Division operands are swapped; e.g., for "40 / 5", this computes 5 / 40 = 0 instead of 40 / 5 = 8.]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [This assignment is useless because it's inside a loop and only affects str[0] once, but more importantly, the following logic tries to adjust operators but uses == instead of =, so no assignment happens.]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+';
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-';
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in every iteration, so previous additions/subtractions are lost. Should initialize sum once before the loop.]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ // @@ [The '=' is at str[m-1], but the loop runs i from 1 to m-1, so str[i] is checked. However, sum is only printed when str[i]=='=', but the accumulation is broken due to repeated reinitialization of sum. Also, if the expression ends with '=', this condition may trigger, but the calculation is already wrong.]
            printf("%d",sum);
        }
    }
    return 0;
}