#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, not a string literal; comparing it to 'NULL' (which should be NULL without quotes) is incorrect and causes logical error. Also, gets() is deprecated and may cause compilation warnings or errors in modern compilers.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [This accesses a[i-1] when i=0, leading to out-of-bounds access (undefined behavior). Also, no check that i>0 before accessing a[i-1].]
            {
                if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')
                {
                    for(j=1;j<a[i+1]-a[i-1];j++)
                    {
                        printf("%c",a[i-1]+j);
                    }
                }
                else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')
                {
                    for(k=1;k<a[i+1]-a[i-1];k++)
                    {
                        printf("%c",a[i-1]+k);
                    }
                }
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Inconsistent indexing: a[1+i] should be a[i+1] for clarity and consistency, though functionally same. However, more critically, this condition does not prevent cases like 'Z-a' from being misprocessed if bounds aren't checked properly—but the main issue is lack of boundary checks on i.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same as above: a[1+i] is equivalent to a[i+1], but inconsistent style. Not a compilation error, but the real problem is missing safety checks.]
                    {
                        printf("%c",a[i-1]+l);
                    }
                }
                else printf("%c",a[i]);
            }
            else printf("%c",a[i]);
        }
    }
    
    return 0;
}