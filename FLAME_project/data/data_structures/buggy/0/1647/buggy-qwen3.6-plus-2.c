#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,j;
    fgets(a,100,stdin);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='a')&&(a[i-1]<='z')) // @@ The code only checks if the character before '-' is lowercase, but fails to verify if the character after '-' is also lowercase and greater than the previous one. This causes incorrect expansion for mixed cases like 'B-e'.
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ This loop executes without validating that a[i+1] is of the same type (lowercase) or greater, leading to wrong output.
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) // @@ Similarly, this block only checks if the preceding character is uppercase, ignoring the type and value of the following character.
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ Expands incorrectly when the next character is not uppercase or not greater.
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) // @@ Only checks if the preceding character is a digit, without ensuring the next character is also a digit and greater.
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ Performs expansion even when the range is invalid across types or order.
                {printf("%c",j);}
            }
            // @@ Missing else clause to handle cases where expansion should not occur (e.g., mixed types or decreasing order), resulting in missing '-' in output.
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}