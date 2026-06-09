#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); // @@ [This assumes the first token is always a number without skipping leading whitespace; however, the problem allows spaces anywhere. If input starts with space, this may fail to read correctly.]
    while(1){//输入 
        scanf("%c",&fu[i]); // @@ [Using %c reads every character including whitespace. This will break if there are spaces between operator and number because it treats space as an operator.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); // @@ [If the previous %c read a space or newline, this %d might still work due to %d skipping whitespace, but the logic of pairing operators and numbers becomes fragile and misaligned when extra spaces exist.]
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