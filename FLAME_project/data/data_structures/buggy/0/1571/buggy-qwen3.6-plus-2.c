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
                for(c=a[i]+1;c<a[i+2];c++) // @@ The original code `c=a[i]=1` is a syntax/logic error. It assigns 1 to a[i] and then to c, instead of starting the expansion from the character after a[i]. It should be `c = a[i] + 1`.
                {
                    b[j++]=c;
                }
                i+=2; // @@ The original code `i++` only skips the '-' character. It needs to skip both the '-' and the end character of the range (a[i+2]) to avoid processing the end character again in the next iteration. So it should be `i += 2` (since the loop also does i++, effectively skipping 2 positions from current i, or rather, we are at index i, next is i+1('-'), next is i+2(end). We want to move past i+2. Current loop increment is 1. So we need to add 2 here so total increase is 3? No. If we are at i, we process i. Then we check i+1. If valid, we expand. We want the next iteration to start at i+3. So we need to increase i by 2 more than the default 1. So `i+=2` is correct because the for loop will do `i++` making it `i+3`).
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