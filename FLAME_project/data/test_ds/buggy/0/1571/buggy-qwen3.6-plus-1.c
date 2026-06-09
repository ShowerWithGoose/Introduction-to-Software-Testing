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
                for(c=a[i]=1;c<a[i+2];c++) // @@ The expression c=a[i]=1 incorrectly assigns 1 to a[i] and initializes the loop counter c to 1, causing it to output ASCII control characters instead of the intended expanded sequence. It should be c=a[i]+1 to start from the next character after the start character.
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
    gets(a);
    expand(a,b);
    puts(b);
    
    
    return 0;
 }