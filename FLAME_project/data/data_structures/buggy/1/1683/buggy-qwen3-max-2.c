#include<stdio.h>
#include<string.h>
char str[15];
int mark[15];
int n;
void rank(int x,int y)
{
    int i=1;
    if(y==0)
    {
        puts(str); // @@ [The string 'str' is not null-terminated properly because spaces are not added between numbers and no '\0' is placed at the end after the last digit. This leads to missing spaces and possible garbage output.]
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                str[x]=i+'0';
                mark[i]=1;
                rank(x+1,y-1); // @@ [When recursing, the next character position is x+1, but this does not leave room for a space after the current digit. As a result, digits are concatenated without spaces (e.g., "12" instead of "1 2"). Also, after placing the last digit, there's no null terminator added before printing.]
                mark[i]=0;
            }
        }
    }
 } 
 int main()
 {
     scanf("%d",&n);
     rank(0,n);
     return 0;
 }