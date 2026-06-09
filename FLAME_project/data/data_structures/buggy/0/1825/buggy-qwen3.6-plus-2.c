#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF)
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++)
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ The condition checks if the character after '-' is within a valid range (e.g., <= '9'), but it fails to check if the character BEFORE '-' is within the corresponding lower bound (e.g., >= '0'). It also doesn't strictly enforce that both characters are of the SAME type (e.g., it might allow mixing if bounds aren't tight, though the current logic is mostly flawed by missing lower bounds for the left character and upper bounds for the right character in a symmetric way). More critically, the logic `s[j-1]>='0' && s[j+1]<='9'` allows cases like '0'-'z' if not carefully bounded, but the main issue here is that it doesn't verify `s[j-1]` is also `<= '9'` and `s[j+1]` is `>= '0'`. Actually, the bigger logical error is that it doesn't ensure the characters are of the *same* category properly. For instance, `s[j-1]>='a'` and `s[j+1]<='z'` ensures left is lowercase start and right is lowercase end, but it doesn't prevent `s[j-1]` being 'a' and `s[j+1]` being 'z' which is fine, but what if `s[j-1]` is 'a' and `s[j+1]` is 'A'? The condition `s[j-1]>='a'` is true, `s[j+1]<='z'` is true. But they are different types. The condition needs to ensure BOTH are lowercase, or BOTH are uppercase, or BOTH are digits. The current OR conditions are partially correct but incomplete. Specifically, `(s[j-1]>='a'&&s[j+1]<='z'...)` does not check if `s[j+1] >= 'a'` or `s[j-1] <= 'z'`. However, the most direct cause for the specific wrong answer "abcdefghijklmnopqrstuuBCDEFF" vs "abcdefghijklmnopqrstuBCDEF" is likely due to how the loop handles the characters surrounding the '-'.
        
        Let's look at the output difference:
        Expected: ...stuBCDEF
        Buggy: ...stuuBCDEFF
        
        The buggy code prints `s[j-1]` in the `if(s[j]!='-')` block before reaching the `-`.
        When `j` is at `-`, it enters the `else`.
        If expansion happens, it prints characters from `s[j-1]+1` to `s[j+1]`.
        It does NOT print `s[j-1]` again inside the expansion block.
        However, `s[j-1]` was already printed when `j` was `j-1` (since `s[j-1] != '-'`).
        So for `a-u`:
        j points to 'a': prints 'a'.
        j points to '-': expands. Prints 'b'...'u'.
        Result: 'a'...'u'. This seems correct for the first part.
        
        Let's look at `B-F`.
        Previous char was 'u'.
        j points to 'B': prints 'B'.
        j points to '-': expands. Prints 'C'...'F'.
        Result: 'B'...'F'.
        
        Why the duplicate 'u' and 'F'?
        
        Let's re-read the input: `a-uB-F`
        
        Indices:
        0: 'a'
        1: '-'
        2: 'u'
        3: 'B'
        4: '-'
        5: 'F'
        6: '\0' (or newline/EOF depending on input)
        
        Loop j=0: s[0]='a' != '-'. Print 'a'.
        Loop j=1: s[1]='-'. Else branch.
           Check condition: s[0]='a', s[2]='u'.
           `s[0]>='a' && s[2]<='z' && s[0]<s[2]` -> True.
           Expansion: n=1. `s[0]+1` = 'b'. Print 'b'. n=2... up to 'u'.
           Prints 'b' through 'u'.
           Note: It does NOT print 'a' here. 'a' was printed at j=0.
           So far: "abu...u" -> "a...u". Correct.
           
        Loop j=2: s[2]='u' != '-'. Print 'u'.
           Ah! Here is the problem. The character 'u' (s[2]) is printed normally because it is not a '-'.
           But it was also the end of the expansion range for the previous '-'.
           The expansion logic prints from `start+1` to `end`.
           The `start` char was printed previously.
           The `end` char is printed in the expansion loop.
           Then, when the loop index `j` advances to the `end` char (s[2]), it is processed again as a normal character and printed again.
           
           Similarly for 'F'.
           Loop j=3: s[3]='B' != '-'. Print 'B'.
           Loop j=4: s[4]='-'. Else branch.
           Check condition: s[3]='B', s[5]='F'.
           `s[3]>='A' && s[5]<='Z' && s[3]<s[5]` -> True.
           Expansion: n=1. `s[3]+1` = 'C'. Print 'C'...'F'.
           Loop j=5: s[5]='F' != '-'. Print 'F'.
           
           So 'u' is printed twice (once in expansion, once as normal char).
           'F' is printed twice (once in expansion, once as normal char).
           
           To fix this, when we perform expansion, we should skip printing the end character later, or structure the loop differently.
           A common way is to only print the start character, then handle the '-' and expansion, and then skip the end character.
           
           In the current code structure:
           When `s[j] == '-'`, we expand. We print `start+1` to `end`.
           The `start` was already printed.
           The `end` is at `j+1`.
           When the loop increments to `j+1`, it will print `s[j+1]` again.
           
           We need to mark that `s[j+1]` has been handled or skip it.
           
           One simple fix is to set `s[j+1]` to a special value or use a flag, but since we can't change structure significantly...
           
           Actually, looking at the reference program, it iterates and looks ahead.
           
           In this buggy program, we can modify the expansion block to NOT print the last character? No, the requirement is to expand `a-d` to `abcd`.
           Reference: `a-d` -> `abcd`.
           My trace:
           j=0 ('a'): print 'a'.
           j=1 ('-'): expand 'b','c','d'.
           j=2 ('d'): print 'd'.
           Output: abcdd.
           
           So the error is definitely that the character after '-' is printed twice.
           
           How to fix with minimal change?
           We can change the condition `if(s[j]!='-')` to also check if the previous character was a '-' that caused expansion? Hard.
           
           Alternatively, inside the expansion block, we can print the whole range `start` to `end`, and then somehow suppress the printing of `start` (which was already printed) and `end` (which will be printed next)?
           
           If we print `start` to `end` in the expansion block:
           j=0 ('a'): print 'a'.
           j=1 ('-'): print 'a','b','c','d'.
           j=2 ('d'): print 'd'.
           Output: abcd d. Still double 'd'. And double 'a' if we print start.
           
           The standard solution for this "lookback" style is often to handle the printing such that you don't print the character if it was part of an expansion.
           
           Let's look at the line causing the issue.
           The line `printf("%c",s[j]);` in the `if(s[j]!='-')` block prints the character.
           If `s[j]` is the character immediately following a '-' that triggered expansion, it should NOT be printed here.
           
           We can add a flag.
           
           However, I must annotate the existing lines.
           
           The error is logically in the `else` block where expansion happens, because it doesn't prevent the subsequent iteration from printing the end character. Or in the `if` block because it doesn't know it should skip.
           
           Since I need to annotate specific lines:
           
           The line `printf("%c",s[j]);` inside `if(s[j]!='-')` is problematic when `s[j]` is the end of an expansion range.
           
           But I can't easily change that without adding state.
           
           Let's look at the expansion loop:
           `while(s[j-1]+n<=s[j+1])`
           It prints `s[j-1]+n`.
           If we change it to print up to `s[j+1]-1`, then `s[j+1]` is not printed in expansion.
           Then `s[j+1]` is printed in the next iteration.
           But `s[j-1]` was printed in previous iteration.
           So `a-d`:
           j=0: print 'a'.
           j=1: expand 'b','c'. (stops before 'd').
           j=2: print 'd'.
           Output: abcd. Correct!
           
           Let's check `a-b`:
           j=0: print 'a'.
           j=1: expand. `n=1`. `s[0]+1` = 'b'. `b <= b` is true. Print 'b'. `n` becomes 2. `a+2` = 'c'. `c <= b` false.
           Wait, if I change condition to `< s[j+1]`, then for `a-b`:
           `a+1` = 'b'. `b < b` false. Loop doesn't run.
           j=2: print 'b'.
           Output: ab. Correct.
           
           So changing the expansion loop condition from `<=` to `<` fixes the double printing of the end character.
           
           Line: `while(s[j-1]+n<=s[j+1])`
           
           Reason: The loop prints characters from `start+1` to `end` inclusive. Since the `end` character is processed and printed in the next iteration of the main loop (as it is not '-'), it gets printed twice. Changing the condition to `<` ensures the `end` character is only printed by the main loop's normal character handling.
        }
            else
            printf("%c",s[j]);
        }
    }
    return 0;
}