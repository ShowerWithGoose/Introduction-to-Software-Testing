/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include <ctype.h>
int main()
{
    int i;
    char pre = 0,c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c == ' ')
            continue; 
        if(c == '-')
        {
            scanf("%c",&c);
            if(((islower(c)&&islower(pre))||(isupper(c)&&isupper(pre))||(isdigit(c)&&isdigit(pre)))&&pre<c)
            {
                for(i = pre;i<=c;i++)
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ 错误：当不满足扩展条件时，pre可能已经在前一步被输出（若前一个字符是普通字符），这里又输出一次pre，导致重复；且pre为0时输出不可见字符。
            }
            pre = 0; // @@ 错误：扩展完成后应将pre更新为c（扩展的最后一个字符），以便后续字符正确衔接；重置为0导致上下文丢失，后续'-'无法正确获得前一个字符。
        }
        else
        {
            if(pre != 0)
                printf("%c",pre); // @@ 错误：延迟输出策略导致最后一个字符（循环结束时pre不为0）无法被输出；同时当连续普通字符时，pre被正确输出后更新为当前字符，但在后续的'-'处理中，pre可能已被输出过，导致else分支中再次输出pre（第20行），引发重复。
            pre = c;    
        }
    }
    return 0;
 }