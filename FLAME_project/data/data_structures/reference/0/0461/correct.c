#include<stdio.h>
int try(int );
int main()
{
    char a[1000],b[26];
    int n=0;
    int i,j,k;
    while(scanf("%s",a)!=EOF)
    {
        for(i=0;a[i]!='\0';i++)
        {
           if(a[i]<a[i+2]&&a[i+1]=='-'&&a[i]>='a'&&a[i+2]<='z')
           {
                n=a[i+2]-a[i];

                for(j=0,k=0;j<n,k<=n-1;j++,k++)
                {
                    b[j]=a[i]+k;
                    printf("%c",b[j]);

                }
                i++;
            }
           else if(a[i]<a[i+2]&&a[i+1]=='-'&&a[i]>='A'&&a[i+2]<='Z')
           {
                n=a[i+2]-a[i];
                for(j=0,k=0;j<n,k<=n-1;j++,k++)
                {
                    b[j]=a[i]+k;
                    printf("%c",b[j]);

                }
                i++;
            }
            else if(a[i]<a[i+2]&&a[i+1]=='-'&&a[i]>='0'&&a[i+2]<='9')
           {
                n=a[i+2]-a[i];
                for(j=0,k=0;j<n,k<=n-1;j++,k++)
                {
                    b[j]=a[i]+k;
                    printf("%c",b[j]);

                }
                i++;
            }
            else printf("%c",a[i]);

        }
    }
    return 0;
}

