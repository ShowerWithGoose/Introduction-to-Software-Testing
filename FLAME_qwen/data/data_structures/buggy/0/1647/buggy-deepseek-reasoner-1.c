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
            if((a[i-1]>='a')&&(a[i-1]<='z')) // @@ missing check for i>0 to avoid out-of-bounds, and missing check that a[i+1] is lowercase and greater than a[i-1]
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ missing verification that a[i+1] is of the same type and greater; also potential out-of-bounds
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) // @@ same issues as above
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ same issues
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) // @@ same issues
            {
                for(j=a[i-1]+1;j<a[i+1];j++) // @@ same issues
                {printf("%c",j);}
            } // @@ missing else clause to print the dash when the left character is not in any valid range [a-z], [A-Z], or [0-9]
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}