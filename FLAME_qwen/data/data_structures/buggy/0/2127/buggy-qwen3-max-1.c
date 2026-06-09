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
            scanf("%c",&c); // @@ [This overwrites the current character 'c' which was '-', losing the ability to correctly handle sequences like "a-b-c"; also, if input ends right after '-', this causes undefined behavior due to reading beyond EOF]
            if(((islower(c)&&islower(pre))||(isupper(c)&&isupper(pre))||(isdigit(c)&&isdigit(pre)))&&pre<c)
            {
                for(i = pre;i<=c;i++) // @@ [This prints from 'pre' to 'c' inclusive, but the problem requires expanding "a-d" to "abcd", meaning it should start from 'pre+1' and go to 'c'; printing 'pre' again duplicates the previous character]
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ [If pre is 0 (e.g., input starts with '-'), this prints a null character followed by '-c', which is incorrect; also, in cases like "a--b", logic fails because pre may not be set properly]
            }
            pre = 0; // @@ [Resetting pre to 0 after processing '-' breaks continuity for chained expansions like "a-b-c", as the next segment won't have correct 'pre']
        }
        else
        {
            if(pre != 0)
                printf("%c",pre); // @@ [This delays printing the previous character until the next non-'-' character is seen, causing missing output if the input ends without a trailing non-'-' character (e.g., "a-b" would not print 'b' at end)]
            pre = c;    
        }
    }
    return 0; 
 }