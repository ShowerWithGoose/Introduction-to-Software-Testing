#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error if compiler enforces secure functions. Also, the logic fails to handle cases where '-' appears at start/end or adjacent characters are not of same type correctly due to flawed condition structure.]
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) // @@ [This condition accesses sim[i-1] and sim[i+1] without checking bounds (e.g., when i=0 or i=strlen(sim)-1), leading to undefined behavior. Also, it assumes expansion is valid just by comparing sim[i+1] > sim[i-1], ignoring type consistency requirement.]
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ [Using separate 'if' instead of 'else if' causes multiple expansions if conditions overlap (though unlikely here), but more critically, the final 'else' only corresponds to the last 'if', not the whole group. This leads to incorrect output like printing '-' even when a valid lowercase or uppercase expansion occurred.]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ [Same issue: this is an independent 'if', so the following 'else' only applies to this block. If digit condition fails but letter condition passed, it will still execute the 'else' and print '-', causing duplicate or wrong output.]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else
            {
                printf("-"); // @@ [This 'else' is attached only to the digit 'if', not the entire set of type checks. So if input is like 'a-d', it expands correctly, but then since digit condition fails, it also prints '-', resulting in "bcd-" instead of "abcd".]
            }
        }
        else
        {
            printf("%c", sim[i]);
        }
    }
    return 0;
}