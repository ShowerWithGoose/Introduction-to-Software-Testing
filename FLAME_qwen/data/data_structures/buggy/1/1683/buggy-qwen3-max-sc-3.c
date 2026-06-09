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
        puts(str); // @@ [The output format requires each integer in a permutation to be separated by a space, but `puts(str)` prints the entire string without spaces between digits and appends a newline. Additionally, `str` is not null-terminated properly before this call, which may lead to undefined behavior.]
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
                rank(x+1,y-1);
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