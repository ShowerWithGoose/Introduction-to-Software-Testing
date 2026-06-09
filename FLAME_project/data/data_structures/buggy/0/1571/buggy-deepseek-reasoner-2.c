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
                for(c=a[i]=1;c<a[i+2];c++) // @@ 错误：应该从 a[i]+1 开始循环，而不是将 a[i] 赋值为 1 并赋值给 c；正确写法应为 for(c = a[i]+1; c < a[i+2]; c++)
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