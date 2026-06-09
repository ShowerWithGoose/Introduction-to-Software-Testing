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
            k++; // @@ [This line incorrectly increments 'k', which is no longer used for tracking number parsing; it should increment 'm' only when encountering an operator, but here it corrupts logic by modifying unused 'k']
        }
        if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
        {
            fu[n]=s1[i];
            n++;
            k=0; // @@ [Resetting 'k' here is meaningless since 'k' is not used in number parsing after removing spaces; this indicates confusion in variable roles]
            m++;
         } 
        
    }

    len2=strlen(fu); // @@ [Variable 'len2' is used but never declared, causing a compilation error]

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
                    fu[i]='+'; // @@ [Changing operator to '+' breaks expression structure; subsequent addition/subtraction pass will misinterpret original intent, especially if first operator was '-', which should negate the following term]
                }
                else
                {
                    fu[i]=fu[i-1]; // @@ [Overwriting current operator with previous one corrupts operator sequence, leading to incorrect evaluation in final pass]
                }
            }
            if(fu[i]=='/')
            {
                temp=num[i+1];
                num[i+1]=num[i]/temp;
                num[i]=0;
                if(i==0)
                {
                    fu[i]='+'; // @@ [Same issue as multiplication: altering operator semantics incorrectly]
                }
                else
                {
                    fu[i]=fu[i-1]; // @@ [Same corruption of operator sequence]
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