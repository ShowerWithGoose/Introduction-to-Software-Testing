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
     ans=ans+num1; // @@ [Incorrect initialization: ans should be 0, not the first number. The first number will be processed as a term when an addition or subtraction operator is encountered. Adding it here causes the output to be just the first number when later operators are not processed due to other errors.]
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
    int len=strlen(op); // @@ [strlen requires a null-terminated string, but op is not null-terminated. Since op[0] is zero (global initialization), strlen returns 0, causing the subsequent loop to be skipped entirely. This leads to ans remaining at its initial (incorrect) value. Use a separate count variable instead.]
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