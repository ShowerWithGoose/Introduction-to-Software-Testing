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
    
    printf("%c", a[0]); // @@ This line incorrectly prints the first character unconditionally, but if the first character is part of a valid expansion (e.g., "a-d"), it should be printed later in the loop. For input "B-e", it prints 'B' here, then the loop processes 'e' without expansion, resulting in "Be" instead of "B-e". The logic should handle the first character within the loop.
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1])
        {
            if(a[i-1]>='a'&&a[i+1]<='z')
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z')
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9')
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else
        {
            printf("%c", a[i]); // @@ When the condition fails (e.g., for "B-e", 'B' and 'e' are different types), this prints the '-' character, but the preceding character 'B' was already printed outside the loop. This causes the output to miss the 'B' before the '-', resulting in "Be" instead of "B-e". The loop should handle all characters, including the first one.
        }
        
    }
    
    
    return 0;
}