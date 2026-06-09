#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); @@ [This assumes the expression starts with a number, but input may start with spaces or even a negative number (though problem says valid expression without parentheses; however, leading space causes scanf to fail reading operator correctly later)]
    while(1){//输入 
        scanf("%c",&fu[i]); @@ [Reading single char after %d leaves newline or space in buffer; also, this reads one operator per loop but doesn't skip whitespace, causing misalignment between operators and numbers]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); @@ [If previous operator read was actually a space or newline due to unhandled whitespace, this will fail to read the next number correctly]
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
            t[j-1]*=num[i]; @@ [Index j may be out of sync because j is only incremented for '+'/'-', but i increments every time; leads to incorrect array access and logic]
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i]; @@ [Same indexing issue as above; also integer division is correct per spec, but indexing error dominates]
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