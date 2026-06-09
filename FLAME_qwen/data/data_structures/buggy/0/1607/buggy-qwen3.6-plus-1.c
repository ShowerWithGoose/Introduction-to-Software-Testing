#include<stdio.h>
#include<string.h>

int main()
{
    char a[800]={0},b[800]={0};
    gets(a);
    int i=0,j=0,sup=0,x=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='-') // @@ When expansion conditions are not met, the '-' character is not copied to the output buffer, causing it to be lost.
        {
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1) // @@ Potential out-of-bounds access if '-' is at index 0.
            {
                sup=a[i+1]-a[i-1]; // @@ Calculates the full difference instead of the number of intermediate characters to insert; should be a[i+1]-a[i-1]-1.
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ Incorrect index advancement; should be x=x+sup to correctly skip the inserted characters.
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1) // @@ Potential out-of-bounds access if '-' is at index 0.
            {
                sup=a[i+1]-a[i-1]; // @@ Calculates the full difference instead of the number of intermediate characters to insert; should be a[i+1]-a[i-1]-1.
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ Incorrect index advancement; should be x=x+sup to correctly skip the inserted characters.
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1) // @@ Potential out-of-bounds access if '-' is at index 0.
            {
                sup=a[i+1]-a[i-1]; // @@ Calculates the full difference instead of the number of intermediate characters to insert; should be a[i+1]-a[i-1]-1.
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1; // @@ Incorrect index advancement; should be x=x+sup to correctly skip the inserted characters.
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