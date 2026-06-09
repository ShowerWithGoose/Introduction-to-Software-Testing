#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num[1010],t[1010];
    char fu[1010],ts[1010];
    int i=1,j=1,k,n,ans;
    
    scanf("%d",&num[0]); // @@ [This assumes the expression starts with a number, but there may be leading spaces before the first number, causing scanf to fail or behave unexpectedly.]
    while(1){//输入 
        scanf("%c",&fu[i]); // @@ [Using %c reads every character including whitespace; this will break parsing if there are spaces between tokens. Also, i starts at 1 but t and ts indexing assumes consistent alignment.]
        if(fu[i]=='='){//遇到‘=’停止输入 
            
            break;
        }
        else{// 
            scanf("%d",&num[i]); // @@ [If the previous scanf("%c") read a space or newline, this may fail to parse the next number correctly, especially if input has irregular spacing.]
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
            t[j-1]*=num[i]; // @@ [Index j may be out of sync with i; j is only incremented for '+'/'-', so for sequences like "2*3*4", j remains 0 and t[-1] could be accessed if j=0 and j-1=-1 (but here j starts at 1, so t[0] is used — however, logic is fragile and relies on correct initialization).]
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i]; // @@ [Same indexing issue as above; also, integer division is required, which C does for integers, so this part is okay if indices are correct.]
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