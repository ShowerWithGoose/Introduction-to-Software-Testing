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
    y=len-1-x; // @@ The variable y calculates the number of digits after the decimal point, but it is not used correctly to determine the exponent for numbers less than 1. The exponent should be based on the position of the first significant digit relative to the decimal point.
    int len2=strlen(ans);
    
    if(len2!=0)
    {
    if((x>=1)&&(s1[0]!='0'))
    {
        printf("%d.%se%d",start,ans,x-1);
    }
    else
    {
        printf("%d.%se%d",start,ans,-y); // @@ For numbers like 0.000...09..., the exponent is not simply -y (negative count of decimal digits). It should be -(number of zeros after decimal before first significant digit + 1). Specifically, if the first significant digit is at index `first_sig_idx`, and decimal point is at `x`, the exponent is `first_sig_idx - x`. Here, `start` is the first significant digit found. We need to find its original index.
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
        printf("%d%se%d",start,ans,-y); // @@ Same error as above: incorrect exponent calculation for small numbers.
    }
    }
    return 0;
 }