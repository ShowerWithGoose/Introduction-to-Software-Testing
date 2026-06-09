#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL)
    {
        int num=0,isok=0;
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
            isok=1;
            }
        }
        if(isok)
        {
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++);
        
            b=num;
            if(s[num-1]=='0')
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]);
                if(a+2!=strlen(s)) // @@ 条件判断错误：当第一个非零数字后面没有其他数字时，不应输出小数点。例如输入0.9，a=0，a+2=2，strlen=3，条件成立导致多输出'.'。应改为判断 s[a+3]!='\0'。
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1);
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1);

            }
        }
        else 
        {
            printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}