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
                printf("%c-%c",pre,c); // @@ [When no previous character is stored (e.g., input starts with '-'), `pre` is 0, leading to printing a null character followed by '-x', which is incorrect. Also, the logic fails to handle cases where '-' appears at the beginning or consecutively.]
            }
            pre = 0; // @@ [Resetting `pre` to 0 after processing '-' causes loss of context for subsequent characters. For example, in "a-b-c", after expanding "a-b", `pre` becomes 0, so "-c" is treated as starting with no prior character, leading to incorrect output like "abc-<null>-c".]
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