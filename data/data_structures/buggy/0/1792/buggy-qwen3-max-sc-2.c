#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ [macro definition syntax error: BIT is not defined and macro name cannot contain space or invalid token]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ [macro definition syntax error: BIT is not defined and macro name cannot contain space or invalid token]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ [macro definition syntax error: BIT is not defined and macro name cannot contain space or invalid token]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 



int main()
{
    char s[100] = {0};
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(int k=1;(s[i-1]+k)<s[i+1];k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
            {
                for(int k=1;(s[i-1]+k)<s[i+1];k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                for(int k=1;(s[i-1]+k)<s[i+1];k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
        }
    }
    return 0;
}