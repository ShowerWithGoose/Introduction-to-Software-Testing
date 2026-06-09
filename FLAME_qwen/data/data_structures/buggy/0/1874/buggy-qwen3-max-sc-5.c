#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, not a string literal; comparing it to 'NULL' (which should be NULL without quotes) is incorrect and causes logical error. Also, gets() is unsafe and deprecated.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [Accessing a[i-1] when i=0 leads to undefined behavior (reading before start of array). Also, no check that a[i+1] exists (could be '\0').]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Inconsistent indexing: uses a[1+i] instead of a[i+1], though equivalent, but typo-prone; more critically, still accesses a[i-1] without ensuring i>0.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same issue: a[1+i] is same as a[i+1], but inconsistent style; also, loop condition may cause missing last character or off-by-one depending on interpretation, but actually correct per problem. However, primary issue remains unsafe access.]
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