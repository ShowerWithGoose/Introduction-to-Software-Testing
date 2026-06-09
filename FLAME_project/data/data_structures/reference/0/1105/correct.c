#include <stdio.h>
char c[50],t[50],a;
int main()
{
    int i,j,k,n,m;
    scanf("%s",c);
    for(i=0;c[i]!='\0';i++)
    {

        if(c[i]=='-')
        {
            if((c[i+1]<='z'&&c[i+1]>='a'&&c[i-1]<='z'&&c[i-1]>='a')||(c[i+1]<='Z'&&c[i+1]>='A'&&c[i-1]<='Z'&&c[i-1]>='A')||(c[i+1]<='9'&&c[i+1]>='0'&&c[i-1]<='9'&&c[i-1]>='0'))
            {
                n=0;
            for(k=i+1;c[k]!='\0';k++)
            {
                t[n]=c[k];n++;
            }
            a=c[i+1];
            for(j=i;(c[j-1]+1)!=a;j++)
            {
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            i=j-1;
            for(k=0;k<n;k++)
            {
                c[j]=t[k];
                j++;
            }
            for(m=0;m<k;m++)
                t[m]='\0';
            }
            else {printf("-");continue;}

        }
        else printf("%c",c[i]);
    }
    printf("\n");
    return 0;
}

