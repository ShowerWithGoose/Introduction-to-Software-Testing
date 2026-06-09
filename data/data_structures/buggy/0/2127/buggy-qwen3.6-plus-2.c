/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include <ctype.h>
int main()
{
    int i;
    char pre = 0,c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c == ' ') // @@ [Logical Error: Silently skips spaces instead of printing them. The problem requires outputting unchanged characters for non-expansion cases.]
            continue; // @@ [Logical Error: Causes spaces to be omitted from the output.]
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
            pre = 0; // @@ [Logical Error: Resets the buffer to 0. Combined with the loop structure, this causes the character immediately following an expansion to be buffered and potentially lost if it is the last character in the input.]
        }
        else
        {
            if(pre != 0)
                printf("%c",pre);
            pre = c;    
        }
    }
    return 0; // @@ [Logical Error: Missing logic to print the final buffered character 'pre' if it is not zero when the input stream ends, causing the last character of the string to be omitted.]
 }