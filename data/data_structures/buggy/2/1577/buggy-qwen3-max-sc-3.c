# include <stdio.h>
# include <string.h>
# include <math.h>
int main()
{
    char s0[50000],s1[50000],fu[50000];
    int num[50000]={0};
    int k=0,len,len1,i=0,m=0,n=0,ans=0,temp;
    gets(s0);
    len=strlen(s0);
    for(i=0;i<len;i++)
    {
        if(s0[i]!=32)
        {
            s1[k]=s0[i];
            k++;
        }     
    }
    len1=strlen(s1);
    
    for(i=0;i<len1;i++)
    {
        
        if(s1[i]>='0'&&s1[i]<='9')
        {
            
            num[m]=(s1[i]-'0')+num[m]*10;
            k++; // @@ [This line incorrectly increments 'k', which is no longer used for digit parsing after space removal; it should increment 'm' only when encountering an operator, but here it corrupts logic by modifying unused 'k'. However, the real critical error is below.]
        }
        if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
        {
            fu[n]=s1[i];
            n++;
            k=0; // @@ [This resets 'k', but 'k' is not used meaningfully in number parsing anymore; however, the major issue is that 'm' is incremented here, which is correct, but note that '=' triggers incrementing m and n, leading to off-by-one issues.]
            m++;
         } 
        
    }

    len2=strlen(fu); // @@ [Error: 'len2' is used but never declared. This causes a compilation error because 'len2' is an undeclared identifier.]
    for(i=0;i<=n-1;i++)
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i]=='*')
            {
                temp=num[i+1];
                num[i+1]=num[i]*temp;
                num[i]=0;
                if(i==0)
                {
                    fu[i]='+';
                }
                else
                {
                    fu[i]=fu[i-1];
                }
            }
            if(fu[i]=='/')
            {
                temp=num[i+1];
                num[i+1]=num[i]/temp;
                num[i]=0;
                if(i==0)
                {
                    fu[i]='+';
                }
                else
                {
                    fu[i]=fu[i-1];
                }
            }
        }
        
    }
    
    ans=num[0];
    for(i=0;i<=n-1;i++)
    {
    if(fu[i]=='+')    
    ans+=num[i+1];
    if(fu[i]=='-')
    ans=ans-num[i+1];
    }
    printf("%d",ans);
    return 0;
}