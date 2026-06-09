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
                for(i = pre;i<=c;i++) // @@ Error: The loop includes the ending character c, but the problem requires that the character after '-' should not be output again in the expansion (it will be handled as the next pre). This causes the ending character to be output twice (once here and once later as pre). The correct loop should be i < c, not i <= c.
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ Error: When expansion is not performed, the program should output the original characters unchanged, but here it outputs pre, '-', and c. However, pre has already been output in the previous iteration (when it was not '-'), so this results in pre being output twice. The correct behavior is to output '-' and c only, since pre was already printed.
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