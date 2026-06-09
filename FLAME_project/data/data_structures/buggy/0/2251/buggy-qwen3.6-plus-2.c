#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) @@ The original condition s[i-1]>='0'&&s[i+1]<='9' is incorrect because it doesn't check if s[i-1] is <= '9' and s[i+1] is >= '0', potentially allowing invalid ranges or mismatched types if not strictly bounded. More importantly, the logic for expansion needs to ensure both characters are of the same type. The original code's condition `s[i-1]>='0'&&s[i+1]<='9'` fails to verify that `s[i-1]` is actually a digit (it could be less than '0' which is impossible for char but logically incomplete) and `s[i+1]` is a digit. However, the critical error in the provided buggy code compared to the reference logic is how it handles the output. Let's look at the specific failure.
            // The test case is a-uB-F.
            // Part 1: a-u. 'a' and 'u' are lowercase. s[i-1]='a', s[i+1]='u'.
            // Condition: s[i-1]>='a' && s[i+1]<='z' && s[i+1]>s[i-1]. This matches the second else-if.
            // lenth = 'u' - 'a' = 20.
            // Loop j=0 to 19. Prints 'a'+0 ... 'a'+19. That is 'a' through 't'.
            // It misses 'u'. The expansion a-u should include u? 
            // Problem description: "expand a-d to abcd". So a-d includes d.
            // The loop `for(j=0;j<lenth;j++) printf("%c",s[i-1]+j);` prints from start char up to start + diff - 1.
            // a-d: diff = 'd'-'a' = 3. Prints 'a', 'b', 'c'. Misses 'd'.
            // So the expansion logic is missing the end character.
            
            // Let's re-read the reference program.
            // Reference: `for(int j=s[i-1]+1;j<s[i+1];j++)` prints intermediate chars.
            // And it prints s[i-1] before? No, the reference program iterates through the string.
            // If s[i] is '-', it checks conditions. If valid, it prints intermediates.
            // Wait, the reference program structure:
            // for each char:
            //   if '-':
            //      if valid expansion:
            //         print intermediates
            //      else:
            //         print '-'
            //   else:
            //      print char
            // This means the start character s[i-1] was already printed in the previous iteration of the loop!
            // And the end character s[i+1] will be printed in a future iteration (when i increments to i+1, s[i] is s[i+1] originally, which is not '-', so it prints it).
            // So the reference program relies on the main loop to print the boundary characters.
            
            // Now look at the buggy code.
            // It also iterates through the string.
            // If s[i] is '-', it performs expansion.
            // The expansion loop: `for(j=0;j<lenth;j++) printf("%c",s[i-1]+j);`
            // This prints from s[i-1] to s[i+1]-1.
            // Since s[i-1] was already printed in the previous iteration (when i was i-1), this results in printing s[i-1] twice.
            // And it stops before s[i+1]. s[i+1] will be printed later when i reaches i+1.
            // So the sequence becomes: [s[i-1]] (from prev iter) + [s[i-1] ... s[i+1]-1] (from expansion) + [s[i+1]] (from next iter).
            // This duplicates the start character and misses nothing? No, it duplicates start.
            // Example a-d:
            // i points to '-'. s[i-1]='a', s[i+1]='d'.
            // Prev iter (i-1) printed 'a'.
            // Expansion: lenth = 3. j=0,1,2. Prints 'a', 'b', 'c'.
            // Next iter (i+1) prints 'd'.
            // Output: aabcd. Expected: abcd.
            // So the expansion should start from s[i-1]+1.
            
            // Let's look at the specific error in the Buggy Output vs Expected.
            // Input: a-uB-F
            // Buggy: aabcdefghijklmnopqrstuBBCDEF
            // Expected: abcdefghijklmnopqrstuBCDEF
            
            // Breakdown of Buggy Output:
            // 1. 'a' (printed when i=0)
            // 2. '-' at i=1. Expansion a-u.
            //    lenth = 'u'-'a' = 20.
            //    Prints 'a'+'0' to 'a'+19 -> 'a' to 't'.
            //    So far: "a" + "abcdefghijklmnopqrst" = "aabcdefghijklmnopqrst"
            // 3. 'u' at i=2 (part of original string, printed normally? No, i increments. After processing i=1, i becomes 2. s[2] is 'u'. It is not '-', so it prints 'u'.)
            //    So far: "...st" + "u" = "...stu"
            // 4. 'B' at i=3. Not '-', prints 'B'.
            // 5. '-' at i=4. Expansion B-F.
            //    lenth = 'F'-'B' = 4.
            //    Prints 'B'+0 to 'B'+3 -> 'B', 'C', 'D', 'E'.
            //    So far: "...uB" + "BCDE" = "...uBBCDE"
            // 6. 'F' at i=5. Not '-', prints 'F'.
            //    Total: aabcdefghijklmnopqrst u B BCDE F -> aabcdefghijklmnopqrstuBBCDEF
            
            // Breakdown of Expected Output:
            // abcdefghijklmnopqrstuBCDEF
            
            // Differences:
            // 1. The initial 'a' is duplicated in buggy output.
            // 2. The 'B' is duplicated in buggy output.
            
            // Reason: The expansion loop includes the start character `s[i-1]` (when j=0), but `s[i-1]` has already been printed by the main loop in the previous iteration.
            // Fix: The expansion loop should start from `s[i-1]+1` or `j=1`.
            
            // Also, there is a second issue. The condition checks.
            // Original: `if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])`
            // This allows s[i-1] to be anything >= '0' (including letters/digits/symbols above '0') and s[i+1] to be anything <= '9'.
            // It does NOT ensure s[i-1] is a digit. For example, if s[i-1] is 'A' (65) and s[i+1] is '9' (57), the condition `s[i+1]>s[i-1]` fails.
            // But if s[i-1] is '0' and s[i+1] is 'z', `s[i+1]<='9'` fails.
            // The main logical flaw regarding "Same Type" is that it doesn't explicitly check `s[i-1] <= '9'` and `s[i+1] >= '0'`.
            // However, the duplication error is the primary cause of the Wrong Answer here.
            
            // Let's annotate the lines with the duplication error.
            // The loop `for(j=0;j<lenth;j++)` starts at 0, printing s[i-1].
            
            {
                lenth=s[i+1]-s[i-1];
                for(j=1;j<lenth;j++) @@ The loop should start from j=1 to avoid reprinting s[i-1] which was already printed in the previous iteration of the main loop. Starting at j=0 causes the start character to be duplicated.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
            {
                lenth=s[i+1]-s[i-1];
                for(j=1;j<lenth;j++) @@ The loop should start from j=1 to avoid reprinting s[i-1] which was already printed in the previous iteration of the main loop. Starting at j=0 causes the start character to be duplicated.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
            {
                lenth=s[i+1]-s[i-1];
                for(j=1;j<lenth;j++) @@ The loop should start from j=1 to avoid reprinting s[i-1] which was already printed in the previous iteration of the main loop. Starting at j=0 causes the start character to be duplicated.
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}