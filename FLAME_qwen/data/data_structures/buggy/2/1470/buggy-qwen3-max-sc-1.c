#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); // @@ [This assumes the expression starts with a number, but input may start with spaces or even a negative number (though problem says valid expression without parentheses; however, leading spaces will cause scanf to fail to read the first number correctly.]
    while(1){//输入 
        scanf("%c",&fu[i]); // @@ [Using %c reads every character including whitespace. The problem states the expression may contain spaces, so this will read spaces as operators, causing logic errors.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); // @@ [If previous %c read a space or invalid operator, this %d may fail to read a number, leaving num[i] uninitialized or causing scanf to block/misbehave.]
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
            ts[j]=fu[i]; // @@ [If fu[i] was a space (due to earlier %c reading space), this stores space as an operator, which later causes the addition/subtraction loop to skip or misbehave because it only checks for '+' and '-'.]
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
        // @@ [Loop has no bounds check and relies on '=' to break. But if ts array doesn't contain '=' due to earlier parsing error (e.g., space consumed '=' or index mismatch), this leads to infinite loop or undefined behavior.]
    }
    
    printf("%d",ans);
    return 0;
}