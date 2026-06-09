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
                for(i = pre;i<=c;i++) // @@ Error: The loop includes the ending character 'c', but the problem requires expanding from pre to nxt-1 (e.g., a-d should output abc, not abcd). The reference program uses `i < nxt`, so this should be `i < c` instead of `i <= c`.
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ Error: When expansion is not performed, the program should output the original characters unchanged, including the '-' symbol. However, this prints pre, '-', and c, but it does not handle the case where pre might be 0 (e.g., at the start of input or after a previous expansion). Additionally, it fails to output the '-' that was read before the second scanf. The correct behavior is to output pre, '-', and c, but only if pre is valid; otherwise, it should handle the '-' separately. More critically, the logic for non-expansion cases is flawed because it consumes the '-' and the next character via scanf, but then outputs them as a group, which can cause issues with subsequent characters. The reference program handles this by outputting pre and '-' separately and setting pre = nxt.
                pre = 0;
            }
            pre = 0; // @@ Error: This line sets pre to 0 after both the expansion and non-expansion cases. However, after expansion, pre should be set to the last character (c) to continue processing, as in the reference program (`pre = nxt`). Setting pre to 0 loses the context for the next character. For example, in input "a-c-g", after expanding "a-c", pre becomes 0, so the next '-' sees pre=0 and fails to expand "c-g".
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