#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]); // @@ [Reading a char after %d may fail to skip whitespace correctly; also, when '=' is read, the loop breaks but i is not incremented, causing m = strlen(str) to be unreliable since str is not null-terminated]
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [str is not null-terminated because it's filled via %c which doesn't add '\0'; strlen behavior is undefined]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [On first iteration i=0, so str[-1] is accessed → undefined behavior / buffer underflow]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same issue: accessing str[-1] when i=0]
            num1[i]=num[i]/num1[i-1]; // @@ [Division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1]]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [This assignment may corrupt operator logic; also, str[0] might be '=' or uninitialized]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ [This is a comparison (==), not assignment (=); typo causes no change]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ [Same typo: == instead of =]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in every iteration, so previous operations are lost]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ // @@ [Loop runs only up to m-1, but '=' may be at position i where i == original input count; also, sum is printed inside loop possibly multiple times or never]
            printf("%d",sum);
        }
    }
    return 0;
}