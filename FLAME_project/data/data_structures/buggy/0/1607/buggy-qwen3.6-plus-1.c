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
            if(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i+1]-a[i-1]>1) // @@ The condition `a[i+1]-a[i-1]>1` fails to handle cases where expansion should not occur due to type mismatch (e.g., 'B' and 'e'). Although this specific block checks for digits, the logic structure below repeats similar flawed checks. More critically, if none of the expansion conditions are met, the '-' is skipped entirely instead of being output.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i+1]-a[i-1]>1) // @@ Same issue: if this condition fails (e.g., mixed case 'B' and 'e'), the code falls through without outputting the '-'.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
                {
                    b[x+j]=a[i-1]+j+1; 
                }
                x=x+sup-1;
            }
            if(a[i+1]>=97&&a[i+1]<=122&&a[i-1]>=97&&a[i-1]<=122&&a[i+1]-a[i-1]>1) // @@ Same issue: if this condition fails, the '-' is lost. Additionally, the variable `x` is not updated correctly in the non-expansion case, leading to missing characters or incorrect positions.
            {
                sup=a[i+1]-a[i-1];
                for(j=0;j<sup;j++)
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