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
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1) @@ The condition `>1` incorrectly prevents expansion for adjacent characters (e.g., a-b); it should be `a[i+1]>a[i-1]` to match the requirement.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) @@ The loop should iterate `sup-1` times (`j<sup-1`) to fill only intermediate characters; otherwise, the character after '-' is duplicated when processed in the next iteration.
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1) @@ Same error: condition should be `a[i+1]>a[i-1]` to allow expansion when the right character is greater.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) @@ Same error: should be `j<sup-1` to avoid duplicating the end character.
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1) @@ Same error: condition should be `a[i+1]>a[i-1]`.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++) @@ Same error: should be `j<sup-1`.
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
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