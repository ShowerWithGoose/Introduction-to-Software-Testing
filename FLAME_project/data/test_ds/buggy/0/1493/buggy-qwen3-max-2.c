#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a);
    
    printf("%c", a[0]); // @@ [If the string starts with '-', this prints the first character before checking if it's part of an expansion pattern, but more critically, if the string is empty, this causes undefined behavior. However, the main issue is in the condition logic below.]
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ [This condition does not verify that both surrounding characters are of the same type (e.g., both lowercase, both uppercase, or both digits). For example, 'B-e' satisfies B < e (since 'B'=66 and 'e'=101), so it incorrectly attempts expansion.]
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [This checks only that the left char is >= 'a' and right char <= 'z', but doesn't ensure the left char is also <= 'z' or that the right char is >= 'a'. So mixed cases like 'B-e' could slip through if other conditions aren't strict. Also, it doesn't confirm both are lowercase.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Same issue: doesn't ensure a[i+1] >= 'A' or a[i-1] <= 'Z', so if a[i-1] is uppercase but a[i+1] is lowercase (like in 'B-e'), this condition may not catch it, but the earlier loose condition already allowed entry.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Similarly, doesn't check that a[i+1] >= '0' or a[i-1] <= '9', so invalid digit-letter combos might be mishandled, though less likely due to ASCII ranges.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        } // @@ [Because the initial condition allows cross-type expansions (like 'B-e'), and the inner conditions don't fully validate both ends are same type, the program expands when it shouldn't. In 'B-e', none of the inner if-blocks execute (since 'B' is uppercase but 'e' is not <= 'Z'), so nothing is printed for the '-', but the '-' itself is also not printed because the else clause is skipped. However, note that in the buggy output "Be", the '-' is missing — meaning the program entered the if(a[i]=='-') block, didn't print anything inside (since no inner condition matched), and thus omitted the '-'. But according to requirements, it should output unchanged, i.e., "B-e". The core error is that when the '-' is encountered and the surrounding chars are not same-type, the program should output the '-', but currently it outputs nothing in that case.]
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}