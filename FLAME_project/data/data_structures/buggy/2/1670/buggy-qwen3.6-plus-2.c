#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ The format string "%d %c" consumes whitespace but fails to handle multiple spaces or specific parsing robustly for the operator following the number. More critically, it reads the operator into str[i] corresponding to the index of the number, which creates alignment issues later.
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ strlen on str is incorrect because str contains operators mixed with potential garbage or uninitialized data if not null-terminated properly, and the logic assumes str holds only operators in a way that aligns with num indices, which is flawed.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ Accessing str[i-1] when i=0 is out of bounds (undefined behavior). Also, the logic for handling multiplication/division precedence is fundamentally broken because it processes left-to-right without proper precedence handling across the whole expression simultaneously.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ Same out-of-bounds access for i=0. Division order is also wrong: num[i]/num1[i-1] should be num1[i-1]/num[i] if num1[i-1] holds the left operand.
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
                str[i]=='+'; // @@ This is a comparison '==', not an assignment '='. It does nothing. Even if fixed, the logic of modifying operators in place to handle precedence is flawed.
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ This is a comparison '==', not an assignment '='. It does nothing.
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ Resetting sum to num1[0] in every iteration of the loop is incorrect. Sum should be initialized once before the loop.
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