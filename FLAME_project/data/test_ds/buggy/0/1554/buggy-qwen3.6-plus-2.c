#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim);
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) 
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++) // @@ The loop condition uses '<' which excludes the end character; it should be '<=' to include the character after the hyphen.
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ Should be 'else if' to prevent falling through to subsequent conditions and the final 'else' block.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++) // @@ The loop condition uses '<' which excludes the end character; it should be '<=' to include the character after the hyphen.
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ Should be 'else if' to maintain proper conditional chaining.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++) // @@ The loop condition uses '<' which excludes the end character; it should be '<=' to include the character after the hyphen.
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else // @@ This 'else' is incorrectly bound to the third 'if'. It executes even when the first or second 'if' is true, printing an extra '-'. It should only execute if none of the type conditions match.
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