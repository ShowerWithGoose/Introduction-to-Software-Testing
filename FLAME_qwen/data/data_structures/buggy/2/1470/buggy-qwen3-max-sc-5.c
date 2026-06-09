#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); @@ [This assumes the expression starts with a number, but there may be leading spaces before the first number which will cause scanf to fail or behave unexpectedly. Also, if the input starts with a negative number (e.g., "-5 + 3 ="), this will not be handled correctly since it expects a digit first.]
    while(1){//输入 
        scanf("%c",&fu[i]); @@ [Using %c reads every character including whitespace. This causes issues because spaces between tokens are read as operators, leading to incorrect parsing. For example, in "5 + 3 =", the space after '5' will be read into fu[i], causing logic errors.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); @@ [If the previous scanf("%c") read a space or invalid operator, this scanf may fail to read an integer, leaving num[i] uninitialized or causing undefined behavior. Additionally, this approach cannot handle negative numbers because it doesn't account for unary minus.]
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
            ts[j]=fu[i]; @@ [If fu[i] was a space (due to earlier %c reading whitespace), this will store a space as an operator, leading to incorrect processing in the final addition/subtraction loop.]
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
        } @@ [This loop does not handle cases where ts[i] is a space or other unexpected character (due to earlier whitespace reading), which would skip valid operations or cause logical errors.]
    }
    
    printf("%d",ans);
    return 0;
}