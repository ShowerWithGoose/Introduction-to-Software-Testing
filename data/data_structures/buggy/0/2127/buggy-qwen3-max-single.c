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
                printf("%c-%c",pre,c); @@ [When no expansion is performed, the program should output the original '-' and the next character, but it also outputs 'pre' which was already printed earlier. This causes duplication of 'pre'. Additionally, if 'pre' is 0 (initial state), printing it leads to undefined behavior or garbage output.]
            }
            pre = 0; @@ [Setting pre to 0 after processing '-' causes loss of context. The next character after '-' (stored in 'c') should become the new 'pre' for subsequent comparisons, not 0.]
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