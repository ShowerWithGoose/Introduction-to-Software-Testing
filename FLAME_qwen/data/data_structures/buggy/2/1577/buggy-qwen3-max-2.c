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
            k++; // @@ [This line incorrectly increments 'k', which is no longer used for number parsing after removing spaces; it should not affect logic but is misleading. However, the real issue is that 'm' is only incremented when encountering an operator, so consecutive digits are parsed correctly, but the bigger problem is below.]
        }
        if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='=')
        {
            fu[n]=s1[i];
            n++;
            k=0;
            m++; // @@ [This increments 'm' to move to next number slot, but note that after the last number (before '='), 'm' is incremented unnecessarily, leading to one extra unused slot. This may cause off-by-one issues later.]
         } 
        
    }

    len2=strlen(fu); // @@ [Error: 'len2' is used but never declared. This causes a compilation error.]
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
                    fu[i]=fu[i-1]; // @@ [This overwrites the current operator with the previous one, which breaks operator sequence for subsequent operations and is logically incorrect.]
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
                    fu[i]=fu[i-1]; // @@ [Same issue as above: corrupting operator sequence.]
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