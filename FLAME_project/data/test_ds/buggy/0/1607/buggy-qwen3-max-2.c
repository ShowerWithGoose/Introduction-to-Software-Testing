#include<stdio.h>
#include<string.h>

int main()
{
    char a[800]={0},b[800]={0};
    gets(a); // @@ [Using 'gets' is unsafe and may cause buffer overflow; more importantly, it's not the source of the logical error here, but the real issue is in expansion logic]
    int i=0,j=0,sup=0,x=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='-')
        {
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [This should be 'x += sup;' because 'sup' characters are added (from a[i-1]+1 to a[i+1]), but current code only advances by sup-1, causing overlap or truncation]
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [Same error: should be 'x += sup;' to correctly advance the index after inserting 'sup' characters]
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ [Same error: should be 'x += sup;' for correct indexing]
            }
            // @@ [Missing 'else' case: when '-' doesn't meet expansion criteria (e.g., mixed types like 'B-e'), the '-' should be copied to output. Current code skips it entirely.]
            
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