#include<stdio.h>

int main()
{
    char a[50];
    int i,j,k,l;
    while(gets(a)!='NULL') // @@ [The return value of gets() is a char*, so comparing it to the string literal 'NULL' (which is actually a multi-character constant, not the null pointer NULL) is incorrect. It should compare to NULL (without quotes). Also, gets() is unsafe and deprecated, but the main error here is using 'NULL' instead of NULL.]
    {
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='-'&&a[i+1]>a[i-1]) // @@ [This condition accesses a[i-1] when i could be 0, leading to out-of-bounds access (undefined behavior). Also, it doesn't check if a[i+1] is within bounds (i.e., not '\0').]
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
                else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[1+i]<='Z') // @@ [Inconsistent indexing: uses a[1+i] instead of a[i+1], though they are equivalent; however, more critically, this line still suffers from the same lack of bounds checking as above. Also, note that the condition a[i+1] >= 'A' was already checked, so only the upper bound needs checking, but the bigger issue is potential access beyond string end.]
                {  
                    for(l=1;l<a[1+i]-a[i-1];l++) // @@ [Same as above: uses a[1+i] inconsistently, but functionally same as a[i+1]. However, if a[i+1] is '\0', this leads to invalid expansion.]
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