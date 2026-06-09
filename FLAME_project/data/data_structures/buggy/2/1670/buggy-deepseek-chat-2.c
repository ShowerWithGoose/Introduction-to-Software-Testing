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
    m=strlen(str); // @@ The length of str includes the '=' character, but the loop below uses m as the number of operators, which may cause out-of-bounds access or incorrect iteration.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ When i=0, str[i-1] accesses str[-1], which is out of bounds and causes undefined behavior.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ Same out-of-bounds issue when i=0.
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){ // @@ This condition checks str[0] repeatedly in the loop, but should check str[i] for each iteration.
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ The assignment uses '==' instead of '=', so it does not actually change str[i].
                str[i]=='+'; // @@ This is a comparison, not an assignment. Should be str[i]='+';
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ Same issue: '==' used instead of '='.
                str[i]=='-'; // @@ This is a comparison, not an assignment. Should be str[i]='-';
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ sum is reset to num1[0] in every iteration, so only the last operation's result is considered, not the cumulative sum.
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