#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ [scanf reads a space or any character after the number; after the last number, the next character is a space, not '=', so the loop condition fails and subsequent parsing is incorrect.]
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [str is not null-terminated; strlen may return garbage value, leading to incorrect loop bounds.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [When i=0, str[-1] is accessed, causing out-of-bounds undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same out-of-bounds issue as above.]
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){ // @@ [Always checks str[0], not str[i]; this logic does not correctly handle order of operations.]
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ [Logic is flawed; intended to change operator but uses comparison instead of assignment for str[i].]
                str[i]=='+'; // @@ [This is a comparison, not an assignment; should be str[i] = '+', but even then the approach is incorrect.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ [Same logical and syntax error.]
                str[i]=='-'; // @@ [Comparison instead of assignment; entire method for handling precedence is wrong.]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in each iteration, losing the accumulated result; should be initialized once outside the loop.]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){
            printf("%d",sum); // @@ [May print multiple times if '=' appears, and sum is incorrect due to resetting each iteration.]
        }
    }
    return 0;
}