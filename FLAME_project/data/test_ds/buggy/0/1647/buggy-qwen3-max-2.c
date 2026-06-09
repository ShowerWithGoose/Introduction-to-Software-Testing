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
            if((a[i-1]>='a')&&(a[i-1]<='z')) @@ // Does not check if a[i+1] is also a lowercase letter or if a[i+1] > a[i-1]; may expand across types (e.g., 'B-e')
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) @@ // Does not check if a[i+1] is also an uppercase letter or if a[i+1] > a[i-1]; may expand across types
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) @@ // Does not check if a[i+1] is also a digit or if a[i+1] > a[i-1]; may expand across types
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else
            {printf("-");} @@ // Missing else case to print '-' when expansion conditions are not fully met (e.g., mixed types like B-e)
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}