#include<stdio.h>
#include<string.h>
int main()
{
    char s1[105],s2[105],ans[105]={0};
    gets(s1);
    int i,j=0,x=0,y,n=0,start,len;
    len=strlen(s1);
    for(i=0;i<len;i++)
    {
        
        if(s1[i]!='.')
        {
            
            if((s1[i]!='0')&&(n==0))
            {
            n=1;
            
            start=s1[i]-'0';
            }
            else if(n==1)
            {
                ans[j]=s1[i];
                j++;
            }
            
            
        }
    
        
    }
    int k;
    for(k=0;k<len;k++)
    {
        if(s1[k]=='.')
        {
            x=k;
            break;
        }
    
    }
    y=len-1-x;
    int len2=strlen(ans);
    
    if(len2!=0)
    {
    if((x>=1)&&(s1[0]!='0'))
    {
        printf("%d.%se%d",start,ans,x-1);
    }
    else
    {
        printf("%d.%se%d",start,ans,-y); // @@ [Error: exponent should be based on the number of decimal places before the first non‑zero digit, not the total digits after the decimal. For inputs like "0.00000009123456789012", -y gives -20 but correct exponent is -8.]
    }
    }
    else
    {
        if((x>=1)&&(s1[0]!='0'))
    {
        printf("%d%se%d",start,ans,x-1);
    }
    else
    {
        printf("%d%se%d",start,ans,-y); // @@ [Same error as above: exponent calculation is wrong for numbers with more than one significant digit.]
    }
    }
    return 0;
 }