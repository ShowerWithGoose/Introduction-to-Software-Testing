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
                printf("%c-%c",pre,c);
            }
            pre = 0; // @@ 错误：在处理完一个扩展后将 pre 置为 0，导致后续连续扩展（如 a-d-g）无法正确获取前一个字符，且丢失了最后一个字符的输出。
        }
        else
        {
            if(pre != 0)
                printf("%c",pre);
            pre = c;    
        }
    }
    return 0;
 }