#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers that remove 'gets' entirely.]
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) 
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ [This should be 'else if' to avoid falling through to the 'else' of the digit block incorrectly.]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ [This should be 'else if'; current structure causes the 'else' to only apply to this last 'if', not the whole group.]
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