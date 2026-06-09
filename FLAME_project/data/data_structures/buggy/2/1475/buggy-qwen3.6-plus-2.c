#include<stdio.h>
#include<string.h>
#include<math.h>
int num[100005];
char op[100005];
int main ()
{
    char c;
    int num1,i=1;
    long long ans=0;
    scanf("%d",&num1);
    num[0]=num1;
     ans=ans+num1; // @@ The initial ans is set to num[0], but later the loop adds/subtracts num[i] starting from i=1. This logic is flawed because if there are no + or - operators, ans remains num[0]. However, the main issue is how ans is calculated at the end. The variable 'ans' is initialized with num[0], but then in the final loop, it adds/subtracts subsequent numbers. This double counts num[0] if not handled carefully, or misses updates if * or / changes num[0]. Actually, the bigger problem is that `ans` is not recalculated from scratch based on the final state of `num` and `op`. It tries to maintain a running sum but fails when * or / modifies previous numbers that were already added to `ans`.
    while(scanf(" %c",&c))
    {
        if(c=='=')
        {
            break;
        } 
        else {
            
        scanf("%d",&num1);
        
         if(c=='-'||c=='+')
        {
            op[i]=c;
            num[i]=num1;
            i++;
        }
        else if(c=='*')
        {
            num[i-1]=num[i-1]*num1; // @@ When * or / is encountered, num[i-1] is updated. However, if num[i-1] was already added to `ans` (which happens if the previous operator was + or -, or if it was the first number), `ans` is not adjusted. The current code maintains `ans` as a running total of terms separated by +/-. But * and / have higher precedence and modify the term in place. If `ans` already includes the old value of `num[i-1]`, it needs to be corrected. The current code does not correct `ans`.
        }
        else if(c=='/'&&num1!=0)
        {
            num[i-1]=num[i-1]/num1; // @@ Same issue as above. `ans` is not updated to reflect the change in `num[i-1]`.
        }
    }
    }
    int len=strlen(op); // @@ strlen expects a null-terminated string. The `op` array is not explicitly null-terminated. While global arrays are zero-initialized, relying on this for logical length is risky if `i` doesn't align with where the zeros are. More importantly, `i` tracks the next available index for op/num. The number of operators stored is `i-1` (since op[1] to op[i-1] are filled). Using strlen might work due to global initialization but is semantically incorrect for tracking count. The loop below uses `len` which might be larger than the actual number of operators if there are trailing zeros or if `i` is not properly mapped. Actually, since `op` is global, it's all zeros. `strlen` will find the first zero. If `op[1]` is set, `op[2]` is 0, strlen returns 1. If `op[1]` and `op[2]` are set, `op[3]` is 0, strlen returns 2. So `len` equals the number of operators stored. This part is technically okay due to global init, but fragile.
    {
        for(i=1;i<=len;i++)
        {
            if(op[i]=='+')
            {
                ans=ans+num[i]; // @@ This adds num[i] to ans. But ans already contains num[0]. And if * or / modified num[0] or any previous num[j], ans was not updated. So ans is incorrect. The correct approach is to either recalculate ans from scratch using the final `num` and `op` arrays, or maintain `ans` correctly during input. The current maintenance is broken.
            }
            else if(op[i]=='-')
            {
                ans=ans-num[i]; // @@ Same issue.
            }
            
        }
    }
    printf("%lld",ans);
        
            
    return 0;
}