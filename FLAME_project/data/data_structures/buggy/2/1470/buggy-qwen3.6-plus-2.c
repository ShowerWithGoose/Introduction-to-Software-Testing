#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]);
    while(1){//输入 
        scanf("%c",&fu[i]); // @@ The format string "%c" reads any character, including whitespace (spaces, newlines). Since the input expression contains spaces (e.g., "10 + 20"), this will read a space into fu[i] instead of the operator '+'. This causes the logic to fail because fu[i] will not match '*', '/', '+', or '-', leading to incorrect parsing of subsequent numbers and operators. It should be " %c" (with a leading space) to skip whitespace, or the input handling should be adjusted to ignore spaces.
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]);
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