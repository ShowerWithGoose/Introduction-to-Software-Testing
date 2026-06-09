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
            if((a[i-1]>='a')&&(a[i-1]<='z')) @@ [Does not check if a[i+1] is also a lowercase letter and greater than a[i-1]; may expand across types like 'B-e']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) @@ [Does not check if a[i+1] is also an uppercase letter and greater than a[i-1]; may expand across types like 'B-e']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) @@ [Does not check if a[i+1] is also a digit and greater than a[i-1]; may expand across types like '0-b']
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else
            {printf("-");} @@ [Missing else clause to print '-' when expansion conditions are not met; current code skips printing '-' entirely in invalid cases]
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}