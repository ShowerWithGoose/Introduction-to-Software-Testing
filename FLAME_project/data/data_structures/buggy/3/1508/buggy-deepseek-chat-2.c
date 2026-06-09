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
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); // @@ [Error: When outputting the fractional part, using s+i+1 includes all characters from that position to the end, including the newline character '\n' from fgets, which causes an extra character in the output. The expected output should not have the newline in the number string.]
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
                printf("%d.",s[0]-'0'); // @@ [Error: This prints the first digit as an integer, but the original string s has been modified by removing the decimal point. The loop below then prints from index 1 onward, but the first digit is already printed, so the output duplicates the first digit. For example, with input "87899.9999999999000999", after removing the decimal, s becomes "878999999999999000999", and this prints "8." then from i=1 prints "78999999999999000999", resulting in "8.78999999999999000999", which is missing one '9' compared to expected "8.78999999999999000999e4". Actually, the expected output has one more '9' after the decimal point. The error is that the first digit is printed separately, but the loop starts from i=1, so the second digit is printed, but the original first digit (s[0]) is already printed, so the output is correct in terms of digits, but the issue is that the loop condition uses i<length, and length was computed before removing the decimal point, so it may include the newline. Additionally, the loop prints all characters including the newline, causing an extra character. The main error is the newline inclusion.]
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