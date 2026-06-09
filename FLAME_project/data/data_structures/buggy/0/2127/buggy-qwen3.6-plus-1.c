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
                for(i = pre;i<=c;i++) // @@ The loop includes the end character 'c', but the next iteration will treat 'c' as a new 'pre'. If the next character is also part of a sequence (like in a-c-g), this causes duplication or logic errors. More critically, if expansion happens, 'pre' should be updated to the last expanded character so it can be compared with the next input. However, the current code sets pre=0 below.
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c);
            }
            pre = 0; // @@ Error: After processing a '-' sequence (whether expanded or not), 'pre' is reset to 0. This breaks the chain for subsequent expansions. For example, in "a-c-g", after expanding "a-c" to "abc", the next character is '-'. The code reads 'g'. It checks if 'g' and 'pre' (which is 0) are same type. They are not. So it prints "0-g" (or garbage/empty for pre) instead of expanding c-g. Actually, since pre is 0, islower(0) is false. So it goes to else. It prints "%c-%c" where pre is 0 (null byte or nothing visible depending on implementation) and c is 'g'. This explains the weird output. The 'pre' should be set to the last character processed (which is 'c' from the expansion or the literal 'c' if not expanded) to allow chaining like a-c-g -> abcdefg.
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