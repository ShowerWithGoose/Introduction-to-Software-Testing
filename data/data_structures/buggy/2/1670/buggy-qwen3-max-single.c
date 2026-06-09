#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ [This reads a number and a character, but skips whitespace. However, the input may have multiple spaces or no space between number and operator, leading to incorrect parsing. Also, when '=' is read, the loop breaks but i is not incremented, so m = strlen(str) will be wrong because str is not null-terminated properly.]
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [str is not null-terminated because we never set str[i+1] = '\0' after reading '=', so strlen(str) returns garbage or undefined value.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [When i=0, str[i-1] accesses str[-1], which is out-of-bounds memory access — undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same as above: when i=0, str[-1] is accessed — undefined behavior. Also, division logic is inverted: it does num[i]/num1[i-1] instead of num1[i-1]/num[i].]
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [This assignment changes the first operator to '+', but doesn't fix the underlying expression structure. Also, this logic is flawed because it doesn't handle operator precedence correctly by modifying operators arbitrarily.]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ [This uses '==' (comparison) instead of '=' (assignment). So it does nothing. Should be str[i] = '+'. Same error below.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ [Same error: '==' instead of '='.]
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
        if(str[i]=='='){ // @@ [The '=' is at index i where the loop broke, but due to incorrect m and indexing, this condition may never trigger. Also, output should happen after full evaluation, not inside loop per element.]
            printf("%d",sum);
        }
    }
    return 0;
}