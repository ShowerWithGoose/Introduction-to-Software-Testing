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
        str[x] = '\0'; // @@ The null terminator is missing, causing puts to print garbage or crash. It must be added before printing.
        puts(str);
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                str[x]=i+'0';
                str[x+1]=' '; // @@ A space separator is missing between numbers. The problem requires integers to be separated by a space.
                mark[i]=1;
                rank(x+2,y-1); // @@ The next position should be x+2 because we added a digit and a space. Previously it was x+1 which would overwrite the space or cause misalignment.
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