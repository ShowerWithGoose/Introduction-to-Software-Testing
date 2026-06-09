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
        printf("e-%d",flag2-flag3); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at index 9 (0-based), and the decimal point is at index 1. The correct exponent should be -(9 - 1) = -8, but the code computes flag2 - flag3 = 9 - 2 = 7, then outputs e-7. The variable flag3 is initialized to 2 and only decremented to 1 in a specific case, which does not correctly represent the position of the decimal point relative to the first significant digit.
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