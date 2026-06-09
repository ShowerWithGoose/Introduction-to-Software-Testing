#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    scanf("%s",&a);
    int i,j=0,r;
    for(i=0;i<1000;i++)
    {
        b[i]=a[i];
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            
            if((a[i-1]>=48&&a[i+1]<=57)||(a[i-1]>=65&&a[i+1]<=90)||(a[i-1]>=97&&a[i+1]<=122))
            {
                  for(r=1;r<=(a[i+1]-a[i-1])-1;r++)
                  {
                      b[j]=a[i-1]+r;
                      j++;
                  }
                  
            }
            else
            {
                b[j]=a[i];
                j++;
            }
            
        }
        else
        {b[j]=a[i];
        j++;}

    }
    
    puts(b);
    return 0;
}
