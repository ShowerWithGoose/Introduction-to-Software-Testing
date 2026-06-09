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
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z')@@ [The if should be an else if to avoid executing the subsequent else when expansion from previous type occurs.]
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9')@@ [The if should be an else if to chain with the previous conditions. As it stands, it is a separate if, causing the else to be executed after any expansion.]
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