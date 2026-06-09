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
                if(atoi(s+i+1)==0)
                {
                    printf("%de-%d\n",s[i]-'0',bit);
                }
                //底数是小数 
                else
                {
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); // @@ [Error: When outputting the fractional part, using s+i+1 includes all characters from that position to the end, including the newline character from fgets, which may cause extra characters in the output. Additionally, the exponent calculation bit=i-1 is incorrect; for numbers like 0.000...xyz, the exponent should be negative and equal to the number of zeros after the decimal point, but here bit is set to i-1, which is off by one (should be i-2). Also, the condition atoi(s+i+1)==0 is flawed because atoi stops at non-digit characters, and the string may contain a newline, leading to incorrect detection of trailing zeros.]
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
                printf("%d.",s[0]-'0'); // @@ [Error: This prints a decimal point unconditionally, but if the number after removing the decimal point is an integer (e.g., "100"), it should not have a decimal point. Also, the loop below prints all remaining characters including the newline, causing extra output. The exponent bit is set to i-1, which is correct for numbers like 87899.999..., but the removal of the decimal point modifies the original string, and the subsequent loop prints from index 1 to length, which includes the newline character, leading to an extra digit in the output compared to expected.]
                for(i=1;i<length;i++)
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