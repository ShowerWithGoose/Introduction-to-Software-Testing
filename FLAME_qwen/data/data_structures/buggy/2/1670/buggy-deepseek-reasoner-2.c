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
    m=strlen(str); // @@ String str may not be null-terminated; strlen may read beyond bounds, causing undefined behavior.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ When i==0, accessing str[-1] is out of bounds, undefined behavior.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ Same out-of-bounds issue when i==0.
            num1[i]=num[i]/num1[i-1]; // @@ Division order is incorrect; left-associative division requires num1[i-1]/num[i], not the reverse.
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ Modifying the first operator unnecessarily; it may change intended expression evaluation.
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ Using comparison (==) instead of assignment (=); no effect on str[i].
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ Same issue: == instead of =.
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ Sum is reset each iteration, losing the accumulated result from previous steps.
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