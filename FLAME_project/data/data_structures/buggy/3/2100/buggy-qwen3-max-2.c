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
    y=len-1-x; // @@ [This computes the number of digits after the decimal point, but when leading zeros exist after the decimal (e.g., "0.000..."), 'y' counts all digits after '.', including leading zeros. However, the exponent should be based on the position of the first non-zero digit, not total digits after '.']
    int len2=strlen(ans);
    
    if(len2!=0)
    {
    if((x>=1)&&(s1[0]!='0'))
    {
        printf("%d.%se%d",start,ans,x-1);
    }
    else
    {
        printf("%d.%se%d",start,ans,-y); // @@ [The exponent is incorrectly calculated as -y. For input "0.00000009123...", y = 17 (digits after '.'), so -y = -17, but expected exponent is -8 because the first non-zero digit '9' is at position 8 after the decimal point (i.e., 0.00000009... => 9.xxxx * 10^-8). The code does not account for leading zeros after the decimal point when computing the exponent.]
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
        printf("%d%se%d",start,ans,-y); // @@ [Same error as above: uses -y instead of correct negative exponent based on first non-zero digit's position.]
    }
    }
    return 0;
 }