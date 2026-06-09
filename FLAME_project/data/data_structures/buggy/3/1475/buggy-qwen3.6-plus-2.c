#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10005]; 
char real[10005];
int main ()
{
    gets(str);
    int i,j,k,flag,flag2,flag3=2;
    char c;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            flag=i;
            break;
        }
        
    }
    if(flag==1)
    {
        if(str[0]=='0')
        {
            for(i=2;i<len;i++)
        {
            if(str[i]!='0')
            {
            flag2=i;    
            c=str[i];
            break;
            }
        }
        real[0]=c;
        if(flag2!=len-1) {
        real[1]='.';}
        else if(flag2==len-1)
        {
            flag3--;
        }
        for(k=flag3,j=flag2+1;j<len;j++,k++)
        {
            real[k]=str[j];
        }printf("%s",real);    
        printf("e-%d",flag2-flag3); // @@ The exponent calculation is incorrect. For input 0.0000000912..., flag2 is the index of '9' (8), and flag3 is 2 (or 1). The exponent should be -(flag2 - flag), which is -(8-1) = -7? No, scientific notation for 0.0...09 is 9.e-(number of zeros + 1). The position of the first non-zero digit is flag2. The decimal point is at flag=1. The exponent is -(flag2 - flag - 1 + 1) = -(flag2 - flag). Wait. 0.0009 -> 9e-4. flag=1, flag2=4. Exponent should be -4. Formula: -(flag2 - 1). Here flag2-flag3 calculates 4-2=2 or 4-1=3. It should be printf("e-%d", flag2 - 1); or more generally based on the shift. The standard formula for 0.digits... is exponent = -(position of first sig digit - 1). Here position is flag2. So exponent is -(flag2 - 1).
        }        
        else 
        {
        printf("%s",str);
        printf("e0");
        }
    }
        
    else if(flag>1)
    {
        real[0]=str[0];
        real[1]='.';
        
        for(k=2,j=1;j<len;j++,k++)
    {
        if(j!=flag)
        {
        real[k]=str[j];
        }
        else {
        k--;}
    }
    printf("%s",real);
    printf("e%d",flag-1);
    }

    return 0;
}