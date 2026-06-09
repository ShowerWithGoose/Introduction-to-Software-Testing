#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, so comparing it to the string literal 'NULL' (which is actually a multi-character constant, not the null pointer) is incorrect. It should compare to NULL (without quotes). Also, gets() is unsafe and deprecated.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [This accesses a[i-1] when i could be 0, leading to out-of-bounds access (undefined behavior). Also, it doesn't check if a[i+1] is within bounds or if both sides are valid characters of the same category before comparing.]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Inconsistent indexing: uses a[1+i] instead of a[i+1], though equivalent, but also fails to validate that the range is valid (e.g., 'Z'-'A' is fine, but what if it's decreasing? Actually condition above checks a[i+1] > a[i-1], so okay, but still unsafe due to missing bounds checks.)]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same as above: a[1+i] is unusual style; more importantly, loop runs while l < (difference), which correctly prints intermediate chars, but only if prior conditions hold. However, the main issue is lack of boundary validation for i-1 and i+1.]
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