#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [gets() returns char*, comparing with string literal 'NULL' is incorrect; should compare with NULL (without quotes). Also, gets() is unsafe and may be unavailable, causing compilation error.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [Accessing a[i-1] when i=0 leads to out-of-bounds read (undefined behavior), though this is a runtime issue; however, the primary compilation error stems from the use of gets() and incorrect NULL comparison.]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Typo: a[1+i] should be a[i+1] for consistency and clarity, though it's functionally equivalent; not a compilation error but a style inconsistency. The real compilation issue is gets() and 'NULL'.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same as above: a[1+i] instead of a[i+1]; not a compilation error.]
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