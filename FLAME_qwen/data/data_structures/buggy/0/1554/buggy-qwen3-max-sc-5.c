#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) // @@ [Accessing sim[i-1] when i=0 leads to out-of-bounds read (undefined behavior); also, condition order risks reading invalid memory before checking bounds]
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ [Using separate 'if' instead of 'else if' causes multiple expansions if conditions overlap (though unlikely here), but more critically, the final 'else' only pairs with the last 'if', leading to incorrect '-' output in some valid cases]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ [Same issue: this 'if' should be 'else if'; otherwise, non-digit ranges might fall through and incorrectly print '-' even when a prior valid range matched]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else
            {
                printf("-"); // @@ [This 'else' only corresponds to the last 'if' (digits), so if input is like 'a-d', it expands correctly, but if input is 'A-D', it expands AND prints '-' because the digit condition fails and triggers this else]
            }
        }
        else
        {
            printf("%c", sim[i]);
        }
    }
    return 0;
}