#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The condition 'gets(a) != "NULL"' is incorrect. gets() returns a pointer to the string or NULL on EOF/error, so it should be compared with NULL (not the string "NULL"). This causes infinite loop as condition never becomes false, leading to Time Limit Exceeded.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1])
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Typo: 'a[1+i]' should be 'a[i+1]' for consistency and correctness, though it's functionally same. However, more critically, after expanding '-', the next character (a[i+1]) should not be printed again by the outer loop, but this code will still print it, causing duplication. But the main TLE cause is the while condition.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++)
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