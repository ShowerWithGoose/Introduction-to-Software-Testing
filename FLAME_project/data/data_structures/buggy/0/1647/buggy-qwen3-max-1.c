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
            if((a[i-1]>='a')&&(a[i-1]<='z')) @@ [Does not check if a[i+1] is a lowercase letter or if it's greater than a[i-1]; may expand across types like 'B-e']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) @@ [Does not check if a[i+1] is an uppercase letter or if it's greater than a[i-1]; may expand across types like 'B-e']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) @@ [Does not check if a[i+1] is a digit or if it's greater than a[i-1]; may expand across types like '4-B']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else
            {printf("-");} @@ [Missing else case to print '-' when expansion conditions are not met; current structure skips printing '-' entirely in invalid cases]
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}