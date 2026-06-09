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
    m=strlen(str); // @@ [Error: strlen(str) counts characters until '\0', but str may not be null-terminated properly if the last read was '=', and the loop breaks before incrementing i, so str[i] is '=' but no null terminator is set. This can cause undefined behavior.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [Error: When i=0, str[i-1] accesses str[-1], which is out of bounds, causing undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Error: Same out-of-bounds issue as above when i=0.]
            num1[i]=num[i]/num1[i-1]; // @@ [Error: Division by zero possible if num1[i-1] is 0, and also the order of operands is reversed compared to the problem's left-to-right evaluation.]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){ // @@ [Error: This condition is checked repeatedly in the loop but does not depend on i, and it incorrectly sets str[0] to '+', losing the original operator.]
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ [Error: Using assignment operator '==' instead of '=' to modify str[i], so the condition has no effect.]
                str[i]=='+'; // @@ [Error: This is a comparison, not an assignment. Should be str[i]='+'.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ [Error: Same issue as above.]
                str[i]=='-'; // @@ [Error: This is a comparison, not an assignment. Should be str[i]='-'.]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [Error: sum is reset to num1[0] in every iteration, so only the last addition/subtraction is considered, not the cumulative sum.]
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