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
        puts(str); // @@ Missing null terminator; should set str[x]='\0' before puts.
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                str[x]=i+'0'; // @@ Missing space after number; should also set str[x+1]=' ' and use x+2 in recursion.
                mark[i]=1;
                rank(x+1,y-1); // @@ Should increment x by 2 to account for space character.
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