#include<stdio.h>
#include<string.h>
int main()
{
    char a[10001];
    int i = 0, j = 1;
    while(scanf("%c", &a[i]) != EOF)
    {
        if(a[i] == '-')
        {

            i++;
            scanf("%c",&a[i]);
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            {
                while(a[i-2] + j <= a[i]) // @@ The loop condition uses '<=' which causes the end character to be printed twice (once here and once in the next iteration or final print). It should be '<' to only print intermediate characters, as the end character will be handled normally or needs to be ensured not to duplicate. However, looking at the logic: if we expand a-c, we want 'b'. The loop prints a+1 ('b'). Then j becomes 2. a+2 is 'c'. Loop stops. The next iteration of while(scanf) will read the next char. But wait, the current char a[i] is 'c'. The code does not print a[i] immediately after expansion. Let's trace.
                // Input: a-c. 
                // 1. Read 'a'. Print 'a'. i=1.
                // 2. Read '-'. i=1. a[1]=='-'.
                // 3. i++ -> i=2. Read 'c'. a[2]='c'.
                // 4. Check expansion: 'a'<'c'. True.
                // 5. Loop: j=1. 'a'+1 = 'b' <= 'c'. Print 'b'. j=2.
                // 6. Loop: 'a'+2 = 'c' <= 'c'. Print 'c'. j=3.
                // 7. Loop: 'a'+3 = 'd' <= 'c'. False.
                // 8. i-- -> i=1.
                // 9. Back to while(scanf). Reads next char.
                // So 'c' is printed inside the loop.
                // Now consider input: a-uB-F.
                // ... expands a-u. Prints b..u.
                // Next char is 'B'.
                // Read 'B'. Print 'B'.
                // Next char is '-'.
                // Read '-'. i points to '-'.
                // i++. Read 'F'.
                // Check expansion B-F.
                // Loop: j=1. 'B'+1='C' <= 'F'. Print 'C'. j=2.
                // ... Print 'D', 'E', 'F'.
                // So 'F' is printed inside the loop.
                // The expected output is abcdef...uBCDEF.
                // The buggy output is abcdef...uB.
                // Why did it stop at B?
                // Let's look at the first expansion a-u.
                // Loop prints b...u.
                // Then i--. i was index of 'u'. Now i is index of '-'.
                // Next scanf reads 'B'.
                // a[i] is 'B'. i increments.
                // Next scanf reads '-'.
                // a[i] is '-'.
                // i++. Reads 'F'.
                // Expansion check for B-F.
                // Wait, the previous expansion ended with printing 'u'.
                // The code structure is:
                // if (a[i] == '-') { ... } else { printf("%c", a[i]); i++; }
                // When expanding a-u:
                // 'a' was printed in else block.
                // '-' detected.
                // 'u' read.
                // Loop prints 'b' through 'u'.
                // i--.
                // Loop continues. scanf reads 'B'.
                // 'B' is not '-'. Else block: printf("%c", 'B'); i++.
                // Next scanf reads '-'.
                // '-' detected.
                // i++. Reads 'F'.
                // Check expansion B-F.
                // Condition: (B<=Z && F<=Z && B>=A && B<F). True.
                // Loop: j=1. B+1=C <= F. Print C. j=2.
                // D, E, F printed.
                // i--.
                // Next scanf. EOF?
                // If input is "a-uB-F\n", then next scanf reads '\n'.
                // '\n' is not '-'. Else block: printf("\n").
                // So output should be ...uBCDEF\n.
                // Why is the buggy output missing CDEF?
                // Let's re-read the buggy output: "abcdefghijklmnopqrstuB".
                // It seems the second expansion didn't happen or failed.
                // Or maybe the first expansion consumed too much?
                // In the first expansion a-u:
                // j starts at 1.
                // While loop condition: a[i-2] + j <= a[i].
                // This prints the end character 'u' as well.
                // Then i--.
                // Next char 'B' is read and printed.
                // Next char '-' is read.
                // Next char 'F' is read.
                // Expansion B-F.
                // j is still 1? No, j is global/static? No, local.
                // j was incremented to 22 (for a->u) in the first loop.
                // j is NOT reset to 1 before the second expansion!
                // That's the bug. j retains its value from the previous expansion.
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]);
                i--;
            }

        }
        else
        {
            printf("%c", a[i]);
            //printf("%d", i);
            i++;
        }

    }
}