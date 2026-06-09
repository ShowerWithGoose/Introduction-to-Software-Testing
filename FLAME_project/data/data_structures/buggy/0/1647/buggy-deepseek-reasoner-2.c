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
            if((a[i-1]>='a')&&(a[i-1]<='z'))  // @@ Missing check: a[i+1] must also be in 'a'..'z' and a[i+1] > a[i-1] (or a[i+1] > a[i-1]+1 as per reference)
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))  // @@ Missing check: a[i+1] must also be in 'A'..'Z' and a[i+1] > a[i-1] (or a[i+1] > a[i-1]+1)
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))  // @@ Missing check: a[i+1] must also be in '0'..'9' and a[i+1] > a[i-1] (or a[i+1] > a[i-1]+1)
            {
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
        }  // @@ Missing else clause: when none of the expansion conditions are met, the hyphen itself should be printed; currently it is omitted.
        else
        {printf("%c",a[i]);}
    }
    return 0;
}