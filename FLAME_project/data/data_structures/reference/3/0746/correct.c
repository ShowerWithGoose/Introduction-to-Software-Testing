#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

char s[106];

int main()
{
    //输入，统计长度
    scanf("%s",s);
    int len=strlen(s);
    //遍历并统计第一个不为0数字的位置和小数点的位置（没有则返回末尾+1），判断是否有第二个数
    int first=-1,point=len,flag=0;
    for(int i=0;i<len;i++){
        if(s[i]=='.')
            point =i;
        else if(s[i]!='0'&&first==-1)
            first=i;
        else if(isdigit(s[i])&&first!=-1)
            flag=1;
    }
    //输入第一个数
    printf("%c",s[first]);
    //若有第二个不为0的数，则输出小数点及之后的数（注意跳过小数点）
    if(flag){
        printf(".");
        for(int i=first+1;i<len;i++){
            if(s[i]=='.')
                continue;
            printf("%c",s[i]);
        }
    }
    //输入e，小数点位置减去第一个数的位置（负则输出，正则减1）
    printf("e%d",(point-first<0)?point-first:point-first-1);
    return 0;
}





