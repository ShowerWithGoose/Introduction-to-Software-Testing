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
            if((a[i-1]>='a')&&(a[i-1]<='z')) // @@ Missing check that a[i+1] is also a lowercase letter and a[i+1] > a[i-1] (or > a[i-1]+1). Also missing else to print '-' when expansion is not performed.
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) // @@ Missing check that a[i+1] is also an uppercase letter and a[i+1] > a[i-1] (or > a[i-1]+1). Also missing else to print '-' when expansion is not performed.
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) // @@ Missing check that a[i+1] is also a digit and a[i+1] > a[i-1] (or > a[i-1]+1). Also missing else to print '-' when expansion is not performed.
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}