#include<stdio.h>
#include<string.h>
int main()
{
    char a[200];
    scanf("%s",a);
    int x=strlen(a);
    int i=0,m=0,n=x;

    if(a[0]=='0'&&a[1]=='.')
    {
        for(i=2; a[i]=='0'&&a[i]!='\0'; i++) m=i-1;
        for(i=x-1; a[i]=='0'; i--) n=i;
        printf("%c",a[m+2]);
        if(m+3!=n) printf(".");
        for(i=m+3; i<=n-1; i++) printf("%c",a[i]);
        printf("e-%d",m+1);

    }

    else
    {
        int q=0;
        for(i=0; a[i]!='.'; i++)
        {

            q++;
        }
        q=q-1;
        for(i=x-1; a[i]=='0'||a[i]=='.'; i--) n=i;
        printf("%c",a[0]);
        if(n!=1) printf(".");
        for(i=1; i<=n-1; i++) if(a[i]!='.') printf("%c",a[i]);

        printf("e%d",q);








    }











    return 0 ;



}

