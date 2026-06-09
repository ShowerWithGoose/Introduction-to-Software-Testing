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
    int len=strlen(op); // @@ [op is not null-terminated, so strlen may read beyond valid data, leading to undefined behavior]
    {
        for(i=1;i<=len;i++) // @@ [loop starts at i=1 but op[0] was never set; also, op indices may not align with num due to missing initialization of op[0]]
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