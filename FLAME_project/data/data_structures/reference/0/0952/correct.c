#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    gets(s);
    int i=0, j=0, sgn1=0, sgn2=0;
    for(i=0; i<strlen(s); i++)
    {
        sgn1=sgn2=0;
        if(i+1<strlen(s)-1&&s[i+1]=='-')
        {
            if(s[i]<='z'&&s[i]>='a')sgn1=1;//判断拓展符前是否为可拓展类型
            else if(s[i]<='Z'&&s[i]>='A')sgn1=2;
            else if(s[i]<='9'&&s[i]>='0')sgn1=3;
            if(s[i+2]<='z'&&s[i+2]>='a')sgn2=1;//判断拓展符后是否为可拓展类型
            else if(s[i+2]<='Z'&&s[i+2]>='A')sgn2=2;
            else if(s[i+2]<='9'&&s[i+2]>='0')sgn2=3;
            if(sgn1==sgn2&&sgn1!=0&&s[i+2]>s[i])//如果找到可拓展的对象
            {
                j=0;
                while(s[i]+j<s[i+2])//打印中间字符
                {
                    printf("%c", s[i]+j);
                    j++;
                }
                i+=1;
            }
            else printf("%c", s[i]);
        }
        else printf("%c", s[i]);
    }
    return 0;
}
