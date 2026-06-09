#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000],b[1000];
    scanf("%s",a);
    int i,j;
    char k;
    for(i=0,j=0; i<strlen(a); i++)
    {
        if(a[i]=='-')
        {
            if(a[i+1]-a[i-1]==1) continue;
            else if((a[i-1]<a[i+1])&&(a[i-1]>='a')&&(a[i+1]<='z'))
            {
                for(k=a[i-1]+1; k<a[i+1]; k++)
                {
                    b[j++]=k;
                }
            }
            else if((a[i-1]<a[i+1])&&(a[i-1]>='A')&&(a[i+1]<='Z'))
            {
                for(k=a[i-1]+1; k<a[i+1]; k++)
                {
                    b[j++]=k;
                }
            }
            else if((a[i-1]<a[i+1])&&(a[i-1]>='0')&&(a[i+1]<='9'))
            {
                for(k=a[i-1]+1; k<a[i+1]; k++)
                {
                    b[j++]=k;
                }
            }
            else b[j++]=a[i];
        }
        else b[j++]=a[i];
    }

    printf("%s",b);

    return 0;
}




