#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ [Macro definition syntax error: BIT is not defined and macro name contains space-like misuse; should be CPL(value, bit)]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ [Same issue: BIT is undefined and macro syntax is invalid]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ [Same issue: BIT is undefined and macro syntax is invalid]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

int dian(char*);

int main()
{
    char str[101] = {0};
    int flag = 0,cnt = 0;
    gets(str); @@ [Use of unsafe function 'gets' which may cause buffer overflow; also deprecated in C11 and removed in later standards]
    if(str[0]=='-')
    {
        printf("%c",str[0]);
        
    }
    else
    {
        if(strlen(str)==1)
        {
            printf("%ce0",str[0]);
        }
        else if(str[0]=='0')
        {
            flag = 1;
            cnt = 1;
            for(int i=2;str[i]!='\0';i++)
            {
                if(str[i]!='0')
                {
                    flag = 0;
                    if(str[i+1]!='\0')
                        printf("%d.",str[i]-'0'); @@ [Incorrect format: should print character directly as %c, not convert to int and use %d]
                    else
                    {
                        printf("%d",str[i]-'0'); @@ [Same issue: should use %c to output digit character]
                        printf("e-%d",cnt);
                    }
                    continue;
                }
                if(flag)
                {
                    cnt++;
                }
                else
                {
                    if(str[i+1]=='\0')
                        printf("%de-%d",str[i]-'0',cnt); @@ [Same issue: %d used for char; also logic may skip printing leading non-zero digit correctly]
                    else
                        printf("%d",str[i]-'0'); @@ [Same issue: should use %c]
                }
            }
        }
        else
        {
            int i=0;
            if(dian(str))
            {
                if(str[i+1]=='\0')
                {
                    printf("%de%d",str[i]-'0',cnt); @@ [cnt is uninitialized (still 0), but exponent should be 0; also %d instead of %c]
                }
                else
                {
                    printf("%d.",str[i]-'0'); @@ [Should use %c for character output]
                }
                flag = 1;
                for(i=1;str[i]!='\0';i++)
                {
                    if(str[i]=='.')
                    {
                        flag = 0;
                        continue;
                    }
                    if(flag)
                    {
                        cnt++; @@ [cnt counts digits after first, but initial cnt=0; this leads to wrong exponent]
                    }
                    printf("%d",str[i]-'0'); @@ [Should use %c to output digit characters]
                }
                printf("e%d",cnt); @@ [Exponent calculation is incorrect due to flawed counting logic]
            }
        }
    }
    return 0;
}

int dian(char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='.')
        {
            return 1;
        }
    }
    return 0;
}