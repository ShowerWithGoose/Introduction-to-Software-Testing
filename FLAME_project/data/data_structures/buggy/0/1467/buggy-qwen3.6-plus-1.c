#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ The condition checks if the previous character is lowercase and the next is within 'a'-'z', but it fails to verify that the previous character is also <= 'z' and the next character is >= 'a'. More importantly, for input "B-e", str[i-1] is 'B' which is not >= 'a', so this block is skipped correctly. However, the logic below falls through.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ Similar to above, this checks for digits. For "B-e", this is skipped correctly.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ This condition checks if the previous char is uppercase ('B' fits) and the next char is <= 'Z'. 'e' is not <= 'Z', so this condition is false. The code does nothing here, which is correct for not expanding. However, the problem is that the '-' itself is never printed when no expansion occurs.
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
            // @@ Missing else clause to print the '-' character when none of the expansion conditions are met. In the case of "B-e", none of the if blocks execute, so the '-' is lost.
        }

    }
    return 0;
}