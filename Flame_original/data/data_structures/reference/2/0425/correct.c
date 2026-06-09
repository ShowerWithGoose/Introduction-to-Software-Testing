#include <stdio.h>
char a[10000];
int b[10000];
int main()
{
    int s=0,i,j,k,c,d,t=1;
    gets(a);
    for(i=j=0;a[i]!=0;i++)
        if(a[i]!=' ')
        a[j++]=a[i];
    a[j]=0;
    for(i=0;a[i]!=0;)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            for(j=0,c=0;a[i]>='0'&&a[i]<='9';i++,j++)
            {
                b[j]=a[i]-'0';
                for(k=0;k<j;k++)
                    b[k]*=10;
            }
            for(k=0;k<j;k++)
                c+=b[k];
        }
        else if(a[i]=='*')
        {
            i++;
            for(j=0,d=0;a[i]>='0'&&a[i]<='9';i++,j++)
            {
                b[j]=a[i]-'0';
                for(k=0;k<j;k++)
                    b[k]*=10;
            }
            for(k=0;k<j;k++)
                d+=b[k];
            c*=d;
        }
        else if(a[i]=='/')
        {
            i++;
            for(j=0,d=0;a[i]>='0'&&a[i]<='9';i++,j++)
            {
                b[j]=a[i]-'0';
                for(k=0;k<j;k++)
                    b[k]*=10;
            }
            for(k=0;k<j;k++)
                d+=b[k];
            c/=d;
        }
        else if(a[i]=='+')
        {
            s+=t*c;
            t=1;
            i++;

        }
        else if(a[i]=='-')
        {
            s+=t*c;
            t=-1;
            i++;
        }
        else
        {
            s+=t*c;
            i++;
        }
    }
    printf("%d",s);
    return 0;
}

