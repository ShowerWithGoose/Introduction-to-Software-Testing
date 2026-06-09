#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    scanf("%s",&s); // @@ [类型不匹配，应使用 scanf("%s",s)；且程序未考虑整数（无小数点）输入情况]
    int i,j;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
            for(i=0;i<strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            printf("e0");    
        }
        else
        {
            for(i=2;i<strlen(s);i++) // @@ [当输入为"0.0"时，循环内找不到非零数字，且后面 else if 会错误输出；全零情况未处理]
            {
                if((s[i]!='0')&&(i!=strlen(s)-1))
                {
                    printf("%c.",s[i]);
                    for(j=i+1;j<strlen(s);j++)
                    {
                        printf("%c",s[j]);
                    }
                    printf("e%d",i-1);
                    break;
                }
                else if(i==strlen(s)-1) // @@ [处理全零输入（如"0.0"）时输出错误格式，应改为单独处理]
                {
                    printf("%ce-%d",s[i],i-1);
                }
            }
        }
    }
    else
    {
        for(i=0;i<strlen(s);i++) // @@ [若输入为整数（无小数点），循环结束后无输出，应添加处理整数情况]
        {
            if(s[i]=='.')
            {
                printf("%c.",s[0]);
                for(j=1;j<=i-1;j++)
                {
                    printf("%c",s[j]);
                }
                for(j=i+1;j<strlen(s);j++)
                {
                    printf("%c",s[j]);
                }
                printf("e%d",i-1);
                break;
            }
        }
    }
    return 0;
 }