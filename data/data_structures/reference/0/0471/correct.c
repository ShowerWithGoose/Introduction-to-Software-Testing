#include <stdio.h>
char a[200],b[200];
int main()
{
    int i=0,j=0,k,l,m;
    gets(a);
    while(a[i]!='\0')
    {
        if(a[i]!='-')
            b[j]=a[i];
        else
        {
            if(a[i+1]-a[i-1]>0)
            {
                if(a[i-1]>='0'&&a[i-1]<='9')
                {
                    if(a[i+1]>='0'&&a[i+1]<='9')
                    {
                        k=i-1;l=i+1;
                        for(m=0;a[k]+m+1<a[l];m++)
                        {
                            b[j+m]=a[k]+m+1;
                        }
                        j+=m;
                        i++;
                        continue;
                    }
                }
                else if(a[i-1]>='a'&&a[i-1]<='z')
                {
                    if(a[i+1]>='a'&&a[i+1]<='z')
                    {
                        k=i-1;l=i+1;
                        for(m=0;a[k]+m+1<a[l];m++)
                        {
                            b[j+m]=a[k]+m+1;
                        }
                        j+=m;
                        i++;
                        continue;
                    }
                }
                else if(a[i-1]>='A'&&a[i-1]<='Z')
                {
                    if(a[i+1]>='A'&&a[i+1]<='Z')
                    {
                        k=i-1;l=i+1;
                        for(m=0;a[k]+m+1<a[l];m++)
                        {
                            b[j+m]=a[k]+m+1;
                        }
                        j+=m;
                        i++;
                        continue;
                    }
                }
            }
                b[j]=a[i];
        }
        j++;
        i++;
    }
    b[j]='\0';
    puts(b);
    return 0;
}



