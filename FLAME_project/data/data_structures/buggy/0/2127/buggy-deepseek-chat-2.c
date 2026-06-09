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
                for(i = pre;i<=c;i++) // @@ Error: The loop includes the ending character 'c', but the problem requires expanding from the character before '-' to the character after '-', and the character after '-' should not be output again in the next iteration. The reference program uses `i < nxt` to avoid duplication. Here, using `i <= c` causes the ending character to be printed twice when the next character is processed.
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ Error: When expansion is not performed, the program should output the original characters unchanged. However, this line outputs pre, '-', and c, but pre may have already been output in the previous iteration (see the else branch below). This leads to duplicate output of pre. The correct approach is to output '-' and c only, since pre was already printed.
            }
            pre = 0;
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