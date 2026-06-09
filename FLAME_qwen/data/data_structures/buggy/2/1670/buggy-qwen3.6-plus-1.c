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
    m=strlen(str); // @@ str is not null-terminated, causing strlen to read out of bounds and return an incorrect length.
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ When i=0, accessing str[-1] causes an out-of-bounds array access.
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){
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
                str[i]=='+'; // @@ Uses comparison operator == instead of assignment =, so the operator is not updated.
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ Uses comparison operator == instead of assignment =, so the operator is not updated.
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ sum is reset to num1[0] in every iteration, preventing correct accumulation of the result.
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