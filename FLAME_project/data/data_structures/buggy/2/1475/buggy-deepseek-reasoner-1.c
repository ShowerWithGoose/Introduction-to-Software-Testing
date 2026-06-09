#include<stdio.h>
#include<string.h>
#include<math.h>
int num[100005];
char op[100005]; // @@ [op array not initialized; used for strlen later without null terminator, leading to undefined behavior and possibly zero length]
int main ()
{
    char c;
    int num1,i=1;
    long long ans=0;
    scanf("%d",&num1);
    num[0]=num1;
     ans=ans+num1;
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
            num[i-1]=num[i-1]*num1;
        }
        else if(c=='/'&&num1!=0)
        {
            num[i-1]=num[i-1]/num1;
        }
    }
    }
    int len=strlen(op); // @@ [op is not null-terminated; strlen may return incorrect value; should manually track number of operators]
    {
        for(i=1;i<=len;i++) // @@ [If len is incorrect, loop may not process operators; also index should start from 1, but with uninitialized op[0], len may be 0 making loop not run]
        {
            if(op[i]=='+')
            {
                ans=ans+num[i];
            }
            else if(op[i]=='-')
            {
                ans=ans-num[i];
            }
            
        }
    }
    printf("%lld",ans);
        
            
    return 0;
}