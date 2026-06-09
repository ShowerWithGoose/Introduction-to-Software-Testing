#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); @@ [This assumes the expression starts with a number, but there may be leading spaces before the first number. The problem states the expression "may contain spaces", so this scanf will fail if the first non-space character is not immediately read as an integer. Additionally, using scanf with %d skips leading whitespace, but the following %c will read the next character including any space after the number, which may not be an operator.]
    while(1){//输入 
        scanf("%c",&fu[i]); @@ [Using %c reads every single character including spaces and newlines. Since the input may contain spaces between tokens, this will incorrectly treat spaces as operators. Also, after reading the first number with %d, the next %c may read a space or newline instead of the actual operator.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); @@ [Similar to the first scanf, this assumes that after reading a (possibly space) character as operator, the next token is a valid integer. However, if fu[i] was actually a space (due to %c reading whitespace), then this tries to read an integer after a space that may not be part of the intended token stream, leading to incorrect parsing or infinite loop if input doesn't match expected format.]
            i++;
        }
    }
    
    t[0]=num[0];
    for(i=1;;i++){//完成乘除法运算，保留加减法运算以及等号 
        if(fu[i]=='='){
            ts[j]=fu[i];
            break;
        }
        else if(fu[i]=='*'){
            t[j-1]*=num[i];
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i];
        }
        else{
            ts[j]=fu[i];
            t[j]=num[i];
            j++;
        }
    }
    
    ans=t[0];
    for(i=1;;i++){//完成加减法运算 
        if(ts[i]=='='){
            break;
        }
        else if(ts[i]=='+'){
            ans+=t[i];
        }
        else if(ts[i]=='-'){
            ans-=t[i];
        }
    }
    
    printf("%d",ans);
    return 0;
}