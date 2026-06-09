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
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1) // @@ [Error] Missing else clause: when expansion conditions are not met for any type, the '-' character is skipped entirely instead of being copied to the output buffer.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ [Error] The loop range includes the end character a[i+1], which causes duplication when the main loop processes a[i+1] in the next iteration. It should only generate characters strictly between a[i-1] and a[i+1].
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [Error] Index update is incorrect due to the duplication in the loop above; it does not correctly advance x for the number of characters actually added.
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1) // @@ [Error] Same missing else clause issue: fails to copy '-' when expansion is invalid.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ [Error] Same duplication error as the first expansion loop.
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [Error] Same index update error.
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1) // @@ [Error] Same missing else clause issue.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ [Error] Same duplication error.
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [Error] Same index update error.
            }
            
        }
        else
        {
        
            b[x]=a[i];
            x++;
        }
    }
    puts(b);
    return 0;
 }