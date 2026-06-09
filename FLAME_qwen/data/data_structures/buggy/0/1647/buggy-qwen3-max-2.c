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
                {printf("%c",j);} @@ [Missing check that a[i+1] is also a lowercase letter and greater than a[i-1]; may access invalid memory when i=0 or i points to last character]
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);} @@ [Missing check that a[i+1] is also an uppercase letter and greater than a[i-1]; may access invalid memory when i=0 or i points to last character]
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);} @@ [Missing check that a[i+1] is also a digit and greater than a[i-1]; may access invalid memory when i=0 or i points to last character]
            }
            else
            {printf("%c",a[i]);} @@ [Missing else clause to print '-' when expansion conditions are not met; original code skips printing '-' in non-expansion cases]
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}