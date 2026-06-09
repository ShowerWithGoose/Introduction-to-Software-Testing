#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) // @@ [Accessing sim[i-1] when i=0 leads to out-of-bounds read (undefined behavior); also, condition order may cause issues if bounds not checked first]
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ [Using separate 'if' instead of 'else if' causes multiple expansions if conditions overlap (though unlikely), but more critically, the final 'else' only applies to the last 'if', leading to incorrect '-' output in some valid cases]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ [Same issue: this 'if' is independent, so if none of the three type checks pass, the 'else' block runs—but if an earlier 'if' passed, this 'if' might fail and still trigger 'else', causing extra '-']
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else
            {
                printf("-");
            }
        }
        else
        {
            printf("%c", sim[i]);
        }
    }
    return 0;
}