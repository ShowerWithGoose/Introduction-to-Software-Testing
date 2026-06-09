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
        scanf("%c",&fu[i]); // @@ [This reads a single character, but after reading an integer with %d, the newline or space remains in the buffer, causing this to read whitespace instead of the operator. This leads to incorrect parsing of operators and numbers.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); // @@ [If the previous scanf("%c") read a whitespace (like '\n' or ' '), then this will fail to read the next number correctly because the input stream is misaligned. Also, if the expression starts with a negative number, this approach fails completely.]
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