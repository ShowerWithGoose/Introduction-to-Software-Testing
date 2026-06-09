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
            if((a[i-1]>='a')&&(a[i-1]<='z'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else
            {printf("%c",a[i]);} // @@ Missing handling for cases where characters are of different types or order is invalid; should print '-' as is, but this else is inside the if(a[i]=='-') block and only triggers when none of the type checks match, which is correct for B-e (since 'B' is uppercase and 'e' is lowercase), but the problem is that the code does not check that both characters are of the same type and that the second character is greater than the first. For "B-e", 'B' is uppercase and 'e' is lowercase, so no expansion should occur, and the '-' should be printed. However, the code's condition for uppercase checks only a[i-1] and not a[i+1], so it incorrectly enters the uppercase branch and expands, causing the wrong output. The fix should include checking a[i+1] is also uppercase, and similarly for other cases.
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}