#include<stdio.h>
#include<string.h>

int main()
{
    char a[800]={0},b[800]={0};
    gets(a);
    int i=0,j=0,sup=0,x=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='-')
        {
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1) // @@ [Condition should be >0 (i.e., a[i+1] > a[i-1]) to handle expansions like "a-b" correctly. Using >1 fails to expand when difference is exactly 1.]
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1) // @@ [Same issue: condition should be >0 instead of >1.]
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1) // @@ [Same issue: condition should be >0 instead of >1.]
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            // Missing else: when none of the above conditions trigger (e.g., dash at start/end, different types, or diff==0), the dash character should be copied to b. Currently it is ignored.
        } // @@ [Missing else branch: the dash is not output when expansion is not performed. Add an else (or else if) to copy a[i] to b and increment x.]
        else
        {
        
            b[x]=a[i];
            x++;
        }
    }
    puts(b);
    return 0;
 }