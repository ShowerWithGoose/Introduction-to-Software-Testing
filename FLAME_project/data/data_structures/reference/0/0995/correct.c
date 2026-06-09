#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char str[10000];
    gets(str);
    int i=0,j;
    char s[10000];
    int chara,lenth;
    for(i=0;str[i];i++)
    {
        if(str[i]=='-'&&i&&str[i-1])//读字符串遇到'-'
        {
            if((isdigit(str[i-1])&&isdigit(str[i+1])||iswlower(str[i-1])&&iswlower(str[i+1])||iswupper(str[i-1])&&iswupper(str[i+1]))&&str[i+1]>str[i-1])//前后相同，后大于前 
            {
                strcpy(s,str+i+1);//记下-后段 
                chara=str[i-1]+1;
                lenth=i+str[i+1]-str[i-1]-1;
                for(j=i;j<lenth;j++)
                {
                    str[j]=chara++;
                }
                str[j]='\0';
                strcat(str,s);
            }
        }
    }
    puts(str);
    return 0;
}
