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
        scanf("%c",&fu[i]); // @@ [This reads a single character including whitespace (like space after number), which may cause misalignment between operators and numbers. The input "10 + 20 * 30 - 40 / 5 =" has spaces, so `scanf("%c")` will read the space instead of '+' first.]
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
            t[j-1]*=num[i]; // @@ [Indexing error: `j` starts at 1, but when the first operator is '+' or '-', `j` increments and `t[j-1]` refers to correct value. However, due to earlier input parsing issue, `fu[i]` might not correspond to the intended operator, leading to wrong operations or skipped terms. Also, `num[i]` may be uninitialized or misaligned because of incorrect parsing.]
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i]; // @@ [Same indexing and alignment issue as above; also integer division is correct per problem, but operands may be wrong due to parsing errors.]
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