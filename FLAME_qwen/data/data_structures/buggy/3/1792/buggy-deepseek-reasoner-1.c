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
        // @@ [Error: Input has no sign per problem description; this branch only prints sign and does nothing else, leading to incomplete output. But since input is unsigned, this branch is never taken, so it's a logical error only if a negative number appears.]
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
                        printf("%d.",str[i]-'0');
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
                        printf("%de-%d",str[i]-'0',cnt);
                    else
                        printf("%d",str[i]-'0');
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
                    printf("%de%d",str[i]-'0',cnt); // @@ [Error: Variable 'cnt' is uninitialized here; it has not been set in this branch, leading to undefined behavior.]
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
                    printf("%d",str[i]-'0');
                }
                printf("e%d",cnt); // @@ [Error: Variable 'cnt' may still be uninitialized because it was not set before the loop (e.g., if the number has no digits before the decimal point? Actually, for numbers like "12.3", cnt is incremented in the loop, but if the number is like "1.2", cnt is incremented once (for the digit '2'), so it's used. However, the initial value of cnt is indeterminate because it was not initialized in this branch. In C, local variables are not automatically initialized, so cnt could be garbage. The previous branch (str[0]=='0') set cnt=1, but this branch does not. So the value is unpredictable. This is a critical bug.]
            }
            // @@ [Error: Missing handling for integer inputs without a decimal point (e.g., "123"). When dian(str) returns 0, no output is produced, resulting in an empty string. The program should convert such integers to scientific notation with a decimal point after the first digit.]
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