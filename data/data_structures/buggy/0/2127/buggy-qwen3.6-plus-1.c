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
            pre = 0; // @@ Error: Should be 'pre = c;' to correctly update the previous character to the one just processed. Setting it to 0 loses the context for subsequent characters, causing incorrect comparisons and potential null character output.
        }
        else
        {
            if(pre != 0)
                printf("%c",pre);
            pre = c;    
        }
    }
    return 0;  // @@ Error: The loop terminates without printing the last character stored in 'pre'. A print statement for 'pre' (if it is not 0) must be added before returning to ensure the final character of the input is output.
 }