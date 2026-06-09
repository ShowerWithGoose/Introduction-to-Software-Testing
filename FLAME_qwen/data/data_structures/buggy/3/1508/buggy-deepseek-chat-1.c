#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//小数点前面是不是零――不是――找小数点后0的个数n――e(-n) 
//                    ――是 ―― 找小数点前数字位数n――e(n-1) 
int main()
{
    char s[105];
    int bit,i,j,k;
    fgets(s,sizeof(s),stdin);
    int length=strlen(s);
//小数点前面是0 
    if(s[0]=='0'&&s[1]=='.')
    {
        for(i=2;i<length;i++)
        {
            if(s[i]!='0')
            {
                bit=i-1;
                // 底数是整数 
                if(atoi(s+i+1)==0) // @@ Error: atoi(s+i+1) may include trailing newline or non-digit characters, and the condition for integer base should check if all remaining digits are zero, not just the numeric value. Also, s+i+1 may be out of bounds if i is the last digit.
                {
                    printf("%de-%d\n",s[i]-'0',bit);
                }
                //底数是小数 
                else
                {
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); // @@ Error: s+i+1 includes the newline character from fgets, causing incorrect output. Also, the exponent should be bit, but bit = i-1, which is correct for the number of leading zeros, but the exponent format should be e-<exponent> without extra spaces.
                }
                break;
            }
        }
    }
//小数点前面不是0 
    else
    {
        for(i=0;i<length;i++)
        {
            if(s[i]=='.')
            {
                bit=i-1;
                for(k=j=0;s[k]!='\0';k++)
                    {
                        if(s[k]!='.')
                        {
                            s[j]=s[k];j++;
                        }
                    }
                s[k]='\0';
                printf("%d.",s[0]-'0');
                for(i=1;i<length;i++) // @@ Error: This loop uses i which is already used in the outer for loop, causing confusion. Also, it prints all characters including the newline, and does not handle the case where the base should be an integer (no decimal point) when there are no digits after the decimal point.
                {
                    if(s[i]!='\n')
                    printf("%c",s[i]);
                }
                printf("e%d",bit);
            }    
        }     
    }
    return 0;
}