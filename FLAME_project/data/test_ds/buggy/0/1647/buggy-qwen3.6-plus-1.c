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
            if((a[i-1]>='a')&&(a[i-1]<='z')) // @@ Missing condition to verify a[i+1] is also a lowercase letter and a[i+1] > a[i-1].
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) // @@ Missing condition to verify a[i+1] is also an uppercase letter and a[i+1] > a[i-1].
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) // @@ Missing condition to verify a[i+1] is also a digit and a[i+1] > a[i-1].
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
        } // @@ Missing else branch to print '-' when the expansion conditions are not met.
        else
        {printf("%c",a[i]);}
    }
    return 0;
}