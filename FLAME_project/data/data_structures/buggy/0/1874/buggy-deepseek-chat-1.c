#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ Error: gets() returns NULL (a pointer), not 'NULL' (a character constant). This comparison is incorrect and will cause the loop to never terminate, leading to Time Limit Exceeded.
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[1+i]<='Z') // @@ Error: The condition is missing the lower bound check for a[i+1] (should be a[i+1]>='A'), and the loop variable l is used but the loop condition uses a[1+i] which is the same as a[i+1] but inconsistent with the variable name. Also, the loop does not print the first character (a[i-1]) or the last character (a[i+1]) of the expansion range.
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