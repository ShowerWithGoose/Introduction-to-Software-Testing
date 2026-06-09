#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ [Macro definition syntax error: BIT is not defined; should be CPL_BIT or similar, and macro body uses undefined BIT]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ [Macro definition syntax error: BIT is not defined; should be SET0_BIT or similar]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ [Macro definition syntax error: BIT is not defined; should be SET1_BIT or similar]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

int dian(char*);

int main()
{
    char str[101] = {0};
    int flag = 0,cnt = 0;
    gets(str); @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; however, the primary issue here is compilation due to macro errors above]
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
                        printf("%d.",str[i]-'0'); @@ [Incorrect format: should output character directly as %c, not convert to int and use %d]
                    else
                    {
                        printf("%d",str[i]-'0'); @@ [Same issue: should use %c to print digit character]
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
                        printf("%de-%d",str[i]-'0',cnt); @@ [Same issue: %d used for char digit]
                    else
                        printf("%d",str[i]-'0'); @@ [Same issue]
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
                    printf("%de%d",str[i]-'0',cnt); @@ [Same issue: %d used for char digit]
                }
                else
                {
                    printf("%d.",str[i]-'0'); @@ [Same issue]
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
                        cnt++;
                    }
                    printf("%d",str[i]-'0'); @@ [Same issue: converting char digit to int then printing with %d instead of using %c]
                }
                printf("e%d",cnt);
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