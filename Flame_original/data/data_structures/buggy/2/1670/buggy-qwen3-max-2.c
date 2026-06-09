#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ [This reads a number and a character, but fails when the expression starts with a negative number or has spaces before operators; also, it assumes every token is a number followed by an operator, which breaks on expressions like "5 - 1" because the '-' is read as the next char after 5, but then the next number is not read correctly due to space handling.]
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [strlen(str) is incorrect because str is filled only up to index i, and the rest is uninitialized; also, str may contain non-null-terminated data since it's filled via scanf without ensuring null termination.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [Accesses str[-1] when i=0, leading to undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same issue: accesses str[-1] when i=0.]
            num1[i]=num[i]/num1[i-1]; // @@ [Division order is wrong: should be num1[i-1]/num[i], not num[i]/num1[i-1]. Also, integer division truncates toward zero, but logic is inverted.]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [This assignment doesn't fix the underlying parsing or evaluation logic; it's a superficial patch that doesn't address operator precedence correctly.]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ [This is a comparison (==), not an assignment (=). Should be str[i] = '+'. Same error below.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ [Same: should be assignment (=), not comparison (==).]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in every iteration, so previous additions/subtractions are lost.]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ // @@ [The '=' is stored at str[i] where i corresponds to the last operator index, but the loop runs up to m-1, and the condition may never trigger if m is not set correctly. Also, output happens inside loop possibly multiple times or never.]
            printf("%d",sum);
        }
    }
    return 0;
}