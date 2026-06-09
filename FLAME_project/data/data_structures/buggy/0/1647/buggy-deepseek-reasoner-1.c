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
            if((a[i-1]>='a')&&(a[i-1]<='z')) // @@ missing check that a[i+1] is also lowercase and greater
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z')) // @@ missing check that a[i+1] is also uppercase and greater
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9')) // @@ missing check that a[i+1] is also digit and greater; also missing else clause to print '-' for unmatched cases
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