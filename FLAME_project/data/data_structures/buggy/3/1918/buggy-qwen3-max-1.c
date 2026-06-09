#include<stdio.h>
#include<string.h>
#include<ctype.h>
char chinput[1000],choutput[1000];
int main()
{
    gets(chinput);
    int len=strlen(chinput),point=0;
    int flag=0,sum=0;
    int i=0,j=0,k=0;
    if(chinput[0]=='0') flag=1; //判断位数正负 
    if(flag==0)
    {
        for(;i<len;i++)
        {
            if(chinput[i]=='.')
            {
                point=i-1;//记录小数点在哪里 
            }
            else if(isdigit(chinput[i]))
            {
                choutput[j]=chinput[i];
                j++;//输入有多少个数字 
            }
        }
        int lenth=j;
        while(choutput[j-1]=='0')
        {
            j--;
            lenth--;//lenth为有效数字个数 
        }
        if(lenth==1)
        {
            printf("%ce%d\n",choutput[0],point);
        }
        else
        {
            printf("%c%c",choutput[0],'.');//输出科学计数法 
            for(k=1;k<lenth;k++)
            {
                printf("%c",choutput[k]);
            }
            printf("%c%d\n",'e',point);
        }
    }
    else if(flag==1)//小于零的整数位数为负数 
    {
        j=0;
        for(i=0;i<len;i++)
        {
            if(chinput[i]=='0')//找小数点后有几个零 
            {
                sum++;
            }
            else if(chinput[i]!='0'&&chinput[i]!='.')
            {
                break;
            }
        }
        for(i=sum+1;i<len;i++)
        {            
            choutput[j]=chinput[i];
            j++;
        }
        int lenth1=j;
        while(choutput[j-1]=='0')
        {
            j--;
            lenth1--;//lenth为有效数字个数 
        }
        if(lenth1==0)
        {
            printf("0e0\n");
        }
        else if(lenth1==1)
        {
            printf("%ce-%d\n",choutput[0],sum); @@ [The exponent should be 'sum - 1' instead of 'sum' because the first non-zero digit is at position sum+1 (0-indexed after decimal), so exponent = -(sum) but since we move to after first digit, it's actually -(sum) => e.g., 0.0009 -> 9e-4, and sum=3 (three zeros), so exponent = -4 = -(sum + 1). However, in this code, sum counts the leading '0' including the one before decimal? Actually, input starts with '0.', so the loop counts the '0' at index 0, then '.' at index 1, then zeros after. But the logic is flawed: it counts all '0's from start, including the leading '0' before '.', which is wrong. For "0.00000009...", it counts the first '0' (at index 0), then continues counting subsequent '0's including those after decimal until non-zero. So sum becomes 8 (including the initial '0'), but should only count zeros after decimal before first non-zero. Thus, exponent calculation is incorrect.]
        }
        else
        {
            for(k=0;k<j;k++)
               {
                printf("%c",choutput[k]); @@ [This prints all significant digits without inserting a decimal point after the first digit, violating the scientific notation format which requires exactly one non-zero digit before the decimal point and the rest after. For example, "9123456789012" should be "9.123456789012".]
            }
            printf("%c-%d\n",'e',sum); @@ [Same exponent error as above: should be -(sum) or more precisely -(number of zeros after decimal + 1). Given sum includes the leading '0' before '.', actual zeros after decimal = sum - 1 (since first char is '0', second is '.'), so exponent = -( (sum - 1) + 1 ) = -sum. But in test case, input "0.00000009..." has 7 zeros after decimal before '9', so exponent should be -8. The code sets sum by counting from i=0: '0','.','0','0',... so when it breaks at '9', sum=8 (counted '0' at start + 7 zeros after decimal). Then it uses sum=8, so prints e-8 which is correct numerically, BUT the mantissa is wrong (missing decimal point). However, the exponent logic here accidentally gives correct value for this test case, but the mantissa formatting is definitely wrong. The primary error is missing decimal point in mantissa for lenth1 > 1.]
        }
        
    }
    return 0;
}