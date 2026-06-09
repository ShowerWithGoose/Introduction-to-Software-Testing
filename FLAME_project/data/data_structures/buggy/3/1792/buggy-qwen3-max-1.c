#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

int dian(char*);

int main()
{
    char str[101] = {0};
    int flag = 0,cnt = 0;
    gets(str);
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
                        printf("%d.",str[i]-'0'); // @@ [This prints a '.' after the first non-zero digit unconditionally if there's more than one digit left, but it should only print one '.' total and then all remaining digits without inserting extra dots. Also, using %d with a single char converted to int is okay, but logic of when to print '.' is flawed.]
                    else
                    {
                        printf("%d",str[i]-'0');
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
                        printf("%de-%d",str[i]-'0',cnt); // @@ [This prints exponent prematurely and doesn't handle trailing digits correctly. The exponent should be printed only once at the end, not inside the loop.]
                    else
                        printf("%d",str[i]-'0'); // @@ [This prints each subsequent digit correctly, but combined with earlier logic, multiple '.' may be printed or exponent printed mid-output.]
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
                    printf("%de%d",str[i]-'0',cnt);
                }
                else
                {
                    printf("%d.",str[i]-'0');
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
                    printf("%d",str[i]-'0'); // @@ [This prints every digit after the first, including those after the decimal point, but cnt is incremented only before encountering '.', which leads to wrong exponent calculation. Also, digits after '.' are printed as integers via %d which is okay, but the logic for exponent is incorrect.]
                }
                printf("e%d",cnt); // @@ [Exponent 'cnt' is not correctly calculated. For numbers like "87899.99...", exponent should be number of digits before decimal minus 1, but here cnt counts digits before '.' incorrectly because flag logic is reversed.]
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