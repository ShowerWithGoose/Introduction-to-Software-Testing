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
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ loop condition should be j<sup-1 to avoid including the end character
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ incorrect x update; should be x=x+sup-1 if loop condition corrected, but currently off
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ same loop bound error
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ same x update error
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1)
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) // @@ same loop bound error
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ same x update error
            }
            // @@ missing else: when no expansion occurs, '-' should be copied to b, but it is not handled here
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