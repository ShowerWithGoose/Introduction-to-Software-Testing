#include<stdio.h>
#include<string.h>
int main()
{
    char s1[105],s2[105],ans[105]={0};
    gets(s1); // @@ [gets() is unsafe and may cause buffer overflow; also, it's deprecated in C11 and removed in C17. Use fgets() instead.]
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
        printf("%d.%se%d",start,ans,x-1); // @@ [The exponent calculation is incorrect for numbers like 0.001; it should be negative based on decimal point position, not x-1.]
    }
    else
    {
        printf("%d.%se%d",start,ans,-y); // @@ [The exponent calculation is incorrect; for numbers like 0.001, y is the number of decimal places, but the exponent should be -(y + number of leading zeros after decimal).]
    }
    }
    else
    {
        if((x>=1)&&(s1[0]!='0'))
    {
        printf("%d%se%d",start,ans,x-1); // @@ [Same exponent issue as above; also, when ans is empty, the format specifier %s will print nothing, but the logic for single-digit numbers may be wrong.]
    }
    else
    {
        printf("%d%se%d",start,ans,-y); // @@ [Same exponent issue; for numbers like 0, this will produce incorrect output.]
    }
    }
    return 0;
 }