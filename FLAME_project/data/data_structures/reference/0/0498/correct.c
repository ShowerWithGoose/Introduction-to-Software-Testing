#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[50000],t;
    scanf("%s",str);
    int i=0;
    int len=strlen(str);
    while(i<len)
    {
        if(str[i]!='-')
        {
            printf("%c",str[i]);
        }
        else if(str[i]=='-')
        {
            if(i>=1&&str[i+1]!='\0'&&((str[i-1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1])||(str[i-1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1])||(str[i-1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1])))
            {
                t=str[i-1]+1;
                while(t<str[i+1])
                {
                    printf("%c",t);
                    t++;
                }
            }
            else
            {
                printf("-");
            }
        }
        else if(str[i]=='\0')
        {
            break;
        }
        i++;
    }
    return 0;
}
//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）


