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
    m=strlen(str); // @@ Error: strlen(str) counts characters until '\0', but str may not be null-terminated properly if the last character is '=' and no '\0' is stored. Also, m includes the '=' character, which may cause out-of-bounds access later.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ Error: When i=0, str[i-1] accesses str[-1], which is out of bounds and undefined behavior.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ Error: Same issue as above; when i=0, str[i-1] is out of bounds.
            num1[i]=num[i]/num1[i-1]; // @@ Error: Division order is reversed; should be num1[i-1]/num[i] for correct integer division.
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){ // @@ Error: This condition is checked repeatedly in the loop but only depends on str[0], which is inefficient and logically incorrect; it should be outside the loop.
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ Error: This logic attempts to replace operators but uses assignment '=' instead of comparison '==' in the next lines, causing no actual change.
                str[i]=='+'; // @@ Error: This is a comparison, not an assignment. Should be str[i]='+'; but even then, the logic is flawed.
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ Error: Same issue as above.
                str[i]=='-'; // @@ Error: This is a comparison, not an assignment. Should be str[i]='-'; but even then, the logic is flawed.
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ Error: sum is reset to num1[0] in every iteration, so only the last addition/subtraction is considered, not the cumulative sum.
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