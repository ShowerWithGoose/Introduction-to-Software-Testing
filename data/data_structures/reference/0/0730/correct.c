#include <stdio.h>
char a[1000000];
int main()
{
    fgets(a,1000000,stdin);
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>a[i-1]&&a[i+1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>a[i-1]&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>a[i-1]&&a[i+1]<='9'))
            {
                for(int j=1;j<a[i+1]-a[i-1];j++)
                printf("%c",a[i-1]+j);
            }
            else
            printf("%c",a[i]);
        }
        else
        printf("%c",a[i]);
    }
    return 0;
}

