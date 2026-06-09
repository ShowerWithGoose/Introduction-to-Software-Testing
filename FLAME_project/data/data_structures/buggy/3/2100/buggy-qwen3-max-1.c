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
    y=len-1-x; // @@ [This computes the number of digits after the decimal point, but it includes trailing zeros that were skipped in 'ans'. The exponent should be based on the position of the first non-zero digit relative to the decimal point, not total digits after decimal.]
    int len2=strlen(ans);
    
    if(len2!=0)
    {
    if((x>=1)&&(s1[0]!='0')) // @@ [This condition assumes numbers like "123.456", but fails to correctly handle cases where the number starts with zero like "0.000...". Also, 'x>=1' is always true if there's a decimal point not at start, but logic for exponent is flawed.]
    {
        printf("%d.%se%d",start,ans,x-1);
    }
    else
    {
        printf("%d.%se%d",start,ans,-y); // @@ [The exponent -y is incorrect. For input "0.00000009123...", y = 19 (digits after '.'), but exponent should be -(position_of_first_nonzero_after_decimal) = -8, not -19 or -20. The correct exponent is -(x+1 - position_of_first_nonzero) or more directly: if first non-zero is at index i (after '.' at x), exponent = -(i - x).]
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
        printf("%d%se%d",start,ans,-y); // @@ [Same exponent error as above; also, this branch handles no fractional part after first non-zero, but still uses wrong y.]
    }
    }
    return 0;
 }