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
                for(i = pre;i<=c;i++) // @@ Loop should be i < c (exclusive) to avoid printing the ending character twice when subsequent expansions use it as the starting character.
                {
                    printf("%c",i);
                }
                pre = 0; // @@ Should be pre = c; to keep the ending character for the next potential expansion. Setting to 0 causes the next dash to be treated as having no preceding character.
            }
            else
            {
                printf("%c-%c",pre,c);
                pre = 0; // @@ Should be pre = c; so that the character after the dash becomes the new preceding character for subsequent input. Setting to 0 loses this character.
            }
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