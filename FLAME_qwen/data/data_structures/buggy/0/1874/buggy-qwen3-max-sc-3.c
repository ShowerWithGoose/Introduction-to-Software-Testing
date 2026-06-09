#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, not a string literal; comparing it to 'NULL' (which should be NULL without quotes) is incorrect and causes logical error. Also, gets() is unsafe and deprecated, but the immediate bug is comparing pointer to string literal "NULL".]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [This accesses a[i-1] when i=0, leading to out-of-bounds read (undefined behavior). Should check i>0 before accessing a[i-1].]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Typo: a[1+i] should be a[i+1] for consistency and correctness, though functionally same; however, more critically, this condition may pass even when types differ (e.g., '9' and 'A') because only range checks are done without ensuring both are uppercase. But main issue is missing bounds check for i>0 and i+1 within string.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same typo a[1+i]; also, if a[i+1] is not greater than a[i-1], loop won't run, but condition already checked a[i+1] > a[i-1], so logic okay if bounds safe. However, no check that i+1 is within string length (i.e., a[i+1] != '\0').]
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