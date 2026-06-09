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
    m=strlen(str); // @@ strlen on non‑null‑terminated array causes undefined behaviour
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ out‑of‑bounds access when i=0
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ same out‑of‑bounds issue
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+';
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){ // @@ intended assignment but uses ==
                str[i]=='+'; // @@ missing assignment, comparison instead
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){ // @@ same logic error
                str[i]=='-'; // @@ missing assignment
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ sum is reset each iteration, discarding previous accumulation
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){
            printf("%d",sum); // @@ prints only the last partial sum
        }
    }
    return 0;
}