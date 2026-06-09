#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ 错误：仅输出最后一个字符，应找到第一个非零数字并输出其后的所有数字，且指数应为正确的负偏移量（例如对于"0.123"应输出"1.23e-1"）
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s);
    } else if(s[0]!='0'&&s[1]!='.'){
        for(int i=0;i<len;i++){
            if(s[i]=='.'){
                a=i;
            }
        }
        printf("%c.",s[0]);
        for(int i=1;i<len;i++){
            if(s[i]!='.'){
                printf("%c",s[i]);
            }
        }
        printf("e%d",a-1);
    }
    return 0;
}