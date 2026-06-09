#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, not comparable to the string literal "NULL"; should compare with NULL (without quotes). Also, gets() is unsafe and deprecated.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [Accesses a[i-1] when i=0, which leads to out-of-bounds read (undefined behavior). Should check that i>0 before accessing a[i-1].]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Inconsistent indexing: uses a[1+i] instead of a[i+1]; though equivalent, it's confusing but not erroneous. However, more critically, no check that i+1 is within bounds (i.e., a[i+1] != '\0').]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same as above: uses a[1+i] inconsistently; also, loop condition may cause issues if a[i+1] - a[i-1] <= 0, but guarded by outer if. Still, missing bounds check for a[i+1].]
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