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
        scanf(" %c",&fu[i]); // @@ [Missing space before %c causes reading of leftover newline or whitespace as operator, leading to incorrect parsing]
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
            t[j-1]*=num[i]; // @@ [Index j may be 0 here if first operator is * or /, causing t[-1] access which is undefined behavior]
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i]; // @@ [Same issue as above: j may be 0, leading to out-of-bounds array access]
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