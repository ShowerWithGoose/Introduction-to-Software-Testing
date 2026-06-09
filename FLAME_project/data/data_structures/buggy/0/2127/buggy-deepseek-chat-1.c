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
                for(i = pre;i<=c;i++) // @@ Error: The loop includes the ending character 'c', but the problem requires expanding from the character before '-' to the character after '-', and the character after '-' should be output as the next 'pre'. Including 'c' in the output causes duplication when the next character is processed. The correct behavior is to output from pre to c-1, then set pre = c.
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ Error: When expansion is not performed, the program should output the original characters including the '-', but it incorrectly outputs pre, '-', and c. However, pre has already been output in the else branch (line 24) when it was not 0, so this leads to duplicate output of pre. The correct approach is to output '-' and c, or handle the output differently.
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