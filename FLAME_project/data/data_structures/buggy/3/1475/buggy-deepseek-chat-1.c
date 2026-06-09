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
        printf("e-%d",flag2-flag3); // @@ Error: The exponent calculation is incorrect. For input "0.00000009123456789012", flag2 is the index of the first non-zero digit '9' (index 9), and flag3 is 2, so flag2-flag3 = 7, but the correct exponent should be -8. The exponent should be the number of zeros after the decimal point before the first non-zero digit, which is flag2 - flag - 1 = 9 - 1 - 1 = 7, but the output shows e-7 instead of e-8. The issue is that flag3 is initialized to 2, which is wrong; it should be 1 to account for the decimal point position correctly. The exponent should be flag2 - flag - 1 = 9 - 1 - 1 = 7, but the expected output is e-8, indicating the exponent calculation is off by 1. Actually, for "0.00000009123456789012", there are 8 zeros after the decimal point before '9', so exponent should be -8. flag2=9, flag=1, so flag2-flag-1=7, but expected is 8. The error is that flag3=2 adds an extra offset; it should be flag3=1 to correctly compute exponent as flag2-flag-1 = 7, but still not 8. Wait, let's recount: "0.00000009123456789012" has 8 zeros after decimal before '9' (positions: after decimal: 0,0,0,0,0,0,0,9 -> 8 zeros). flag2=9 (index of '9'), flag=1 (index of '.'), so exponent = flag2 - flag - 1 = 9-1-1=7, but expected is 8. This suggests the indexing is off by one. Actually, the string indices: str[0]='0', str[1]='.', str[2]='0', str[3]='0', str[4]='0', str[5]='0', str[6]='0', str[7]='0', str[8]='0', str[9]='9'. So flag2=9, flag=1, number of zeros after decimal = flag2 - flag - 1 = 9-1-1=7, but there are 8 zeros. The error is that the loop starts from i=2, missing the first zero after decimal? No, str[2] is the first zero. The count should be flag2 - flag - 1 = 7, but actual zeros are 8. This means the exponent should be 8, so the formula should be flag2 - flag - 1 + 1 = flag2 - flag = 8. So the correct exponent is flag2 - flag = 9 - 1 = 8. But the code uses flag2-flag3, and flag3=2, giving 9-2=7. To get 8, flag3 should be 1. So the error is that flag3 is initialized to 2 instead of 1.
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