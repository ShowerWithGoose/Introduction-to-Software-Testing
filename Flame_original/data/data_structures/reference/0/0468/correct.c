#include<stdio.h>
#include<string.h>
char a[200];
int main()
{
 gets(a);
 int i,j,k;
 for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!='-'&&a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        else if(a[i+1]=='-')
        {
            if(a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else if(a[i]>='A'&&a[i]<='Z'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else if(a[i]>='a'&&a[i]<='z'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i+2]>a[i])
            {
                for(j=a[i];j<a[i+2];j++)
                    printf("%c",j);
            }
            else
            printf("%c%c",a[i],a[i+1]);

        }
    }
 return 0;
}



