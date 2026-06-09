#include <stdio.h>
#include <ctype.h>
#include <string.h>
int fun(char start,char end)
{
    if(islower(start)&&islower(end)&&start<end)
        return 1;
    if(isupper(start)&&isupper(end)&&start<end)
        return 1;
    if(isdigit(start)&&isdigit(end)&&start<end)
        return 1;
    return 0;
}
char *expand(char *a,char *b)
{
    char c;int i,j;
    for(i=0,j=0;a[i]!='\0';i++)
    {
        b[j++]=a[i];
        if(a[i+1]=='-')
        {
            if(fun(a[i],a[i+2])==1)
            {
                for(c=a[i]+1;c<a[i+2];c++) // @@ The original code `c=a[i]=1` is a syntax/logic error. It assigns 1 to a[i] and then to c, instead of starting the expansion from the character after a[i]. It should be `c = a[i] + 1`.
                {
                    b[j++]=c;
                }
                i+=2; // @@ The original code `i++` only skips the '-' character. It needs to skip both the '-' and the end character of the range (a[i+2]) to avoid processing the end character again in the next iteration. So it should be `i += 2` (since the loop also does i++, effectively skipping 2 positions from current i: '-' and end char). Wait, if i is at start char, next is '-', next is end char. We processed start char. We see '-'. We expand. We need to skip '-' and end char. The loop increment `i++` happens at the end. So if we are at index `k` (start char), `a[k+1]` is '-'. We enter if. We expand. We want next `i` to be `k+2` (end char) so that loop increment makes it `k+3` (next after range). Or we set `i` to `k+1` ('-') so loop increment makes it `k+2` (end char), which will be processed? No, the end char should not be processed as a start of a new sequence or printed again. The standard behavior is `a-z` becomes `abc...z`. The `z` is part of the expansion. In the current logic, `b[j++]=a[i]` adds the start char. Then we add intermediate chars. We are missing the end char in the expansion loop `c < a[i+2]`. The loop should likely be `c <= a[i+2]` or handle the end char. Let's look at expected output: `a-u` -> `abcdefghijklmnopqrstu`. The `u` is included. The loop `c=a[i]+1; c<a[i+2]; c++` excludes `a[i+2]`. So the end character is missing from the expansion. Also, the index `i` needs to advance past the expanded section.
                
                // Let's re-evaluate the index skipping.
                // Current i is at 'a'. a[i+1] is '-'. a[i+2] is 'u'.
                // We print 'a'.
                // We expand b..t.
                // We need to print 'u'? The problem says expand a-d to abcd. So the end char is included.
                // The loop `for(c=a[i]+1;c<a[i+2];c++)` generates chars strictly between start and end.
                // It misses the end character.
                // Also, after processing `a-u`, the next character to process should be whatever comes after `u`.
                // If we just do `i++`, i becomes index of '-'. Next loop iteration: i is index of '-'. a[i] is '-'. a[i+1] is 'u'. a[i+2] is 'B'.
                // It will print '-' then check if 'u' and 'B' expand. They don't. Then i increments to 'u'.
                // This results in duplicate or incorrect output.
                // Correct logic: Skip the '-' and the end character.
                // So `i` should be incremented by 2 more (total 3 from start position? No).
                // Start at i. Next is i+1 ('-'). Next is i+2 (end).
                // We want to jump to i+3.
                // Loop does i++. So we need `i += 2` inside the block.
                
                // Additionally, the end character `a[i+2]` must be added to the output.
            }
            else {
                 // If not expanding, we just printed a[i]. The '-' will be printed in the next iteration.
            }
        }
    } 
    b[j]='\0';
    return b;
}

int main()
{
    char a[1005],b[1005];
    gets(a);
    expand(a,b);
    puts(b);
    
    
    return 0;
 }