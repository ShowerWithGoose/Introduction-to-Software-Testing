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
    
    printf("%c", a[0]); // @@ Unconditionally prints the first character, which may cause duplicate output or incorrect behavior if the string starts with '-' or is empty.
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ Checking a[i-1]<a[i+1] here without verifying character types first may cause the program to enter the block and skip printing '-' when types mismatch.
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ Missing upper bound check for a[i-1] and lower bound check for a[i+1], failing to ensure both characters are strictly lowercase letters.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ Missing upper bound check for a[i-1] and lower bound check for a[i+1], failing to ensure both characters are strictly uppercase letters.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ Missing upper bound check for a[i-1] and lower bound check for a[i+1], failing to ensure both characters are strictly digits.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else // @@ This else corresponds to the outer if. If a[i] is '-' and a[i-1]<a[i+1] but types mismatch, '-' is not printed. The else should handle cases where expansion conditions are not met.
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}