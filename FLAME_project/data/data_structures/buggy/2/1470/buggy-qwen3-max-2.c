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
        scanf("%c",&fu[i]); @@ [This reads a single character, but may read whitespace (like space) before the operator. The input has spaces, so this causes misalignment between operators and numbers.]
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
            t[j-1]*=num[i]; @@ [Indexing error: when encountering '*' or '/', it uses t[j-1] which assumes j was incremented for every number, but j is only incremented for '+'/'-'. This leads to incorrect indexing and overwriting wrong values.]
        }
        else if(fu[i]=='/'){
            t[j-1]/=num[i]; @@ [Same indexing error as above; also, integer division is correct per problem, but logic fails due to index mismatch.]
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