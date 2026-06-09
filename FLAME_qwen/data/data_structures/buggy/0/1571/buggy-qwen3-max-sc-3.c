#include <stdio.h>
#include <ctype.h>
#include <string.h>
int fun(char start,char end)
{
    if(islower(start)&&islower(end)&&start<end)
        return 1;
    if(isupper(start)&&isupper(end)&&start<end)
        return 1;
    if(isdigit(start)&&isdigit(end)&&start<end)
        return 1;
    return 0;
}
char *expand(char *a,char *b)
{
    char c;int i,j;
    for(i=0,j=0;a[i]!='\0';i++)
    {
        b[j++]=a[i];
        if(a[i+1]=='-')
        {
            if(fun(a[i],a[i+2])==1)
            {
                for(c=a[i]=1;c<a[i+2];c++) // @@ [Typo: 'a[i]=1' should be 'a[i]+1'; assignment instead of addition causes incorrect loop start and modifies input string]
                {
                    b[j++]=c;
                }
                i++;
            }
        
        }
    } 
    b[j]='\0';
    return b;
}

int main()
{
    char a[1005],b[1005];
    gets(a); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; though not a compilation error, it's deprecated and may cause issues in some environments]
    expand(a,b);
    puts(b);
    
    
    return 0;
 }