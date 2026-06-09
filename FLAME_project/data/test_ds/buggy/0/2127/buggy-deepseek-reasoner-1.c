#include<stdio.h>
#include <ctype.h>
int main()
{
    int i;
    char pre = 0,c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c == ' ')
            continue; 
        if(c == '-')
        {
            scanf("%c",&c);
            if(((islower(c)&&islower(pre))||(isupper(c)&&isupper(pre))||(isdigit(c)&&isdigit(pre)))&&pre<c)
            {
                for(i = pre;i<=c;i++) // @@ error: loop should be i < c (exclusive of c) to avoid double printing the end character
                {
                    printf("%c",i);
                }
            }
            else
            {
                printf("%c-%c",pre,c); // @@ error: should output only pre and the dash, not the character after dash; e.g., printf("%c-", pre); then keep c as pending
            }
            pre = 0; // @@ error: setting pre to 0 loses the state; after expansion set pre = c (since c is not printed yet with corrected loop), after failure set pre = c (without printing c)
        }
        else
        {
            if(pre != 0)
                printf("%c",pre);
            pre = c;    
        }
    }
    return 0; // @@ error: missing final output of any remaining character (like if(pre) putchar(pre);)
}