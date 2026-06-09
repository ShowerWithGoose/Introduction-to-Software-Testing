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
    int len=strlen(op); // @@ [Error: strlen(op) is used to determine the length of the operator array, but op is not null-terminated because it is filled character by character without adding a '\0' at the end. This leads to undefined behavior when strlen reads past the initialized portion of the array.]
    {
        for(i=1;i<=len;i++)
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