#include<stdio.h>
#include<ctype.h>
int main()
{
    char a[100],b[100];
    int i=0,j=0,k;
    scanf("%s",&a);
    while(a[i]!='\0')
    {
        if(isdigit(a[i])||islower(a[i])||isupper(a[i]))
            b[j++]=a[i++];
        if(a[i]=='-')
        {
            if(a[i+1]-a[i-1]>0&&isdigit(a[i-1])&&isdigit(a[i+1]))
            {
                for(k=1; k<=a[i+1]-a[i-1]-1; k++)

                    b[j++]=a[i-1]+k;
            }
            else if(a[i+1]-a[i-1]>0&&isupper(a[i-1])&&isupper(a[i+1]))
            {
                for(k=1; k<=a[i+1]-a[i-1]-1; k++)

                    b[j++]=a[i-1]+k;
            }
            else if(a[i+1]-a[i-1]>0&&islower(a[i-1])&&islower(a[i+1]))
            {
                for(k=1; k<=a[i+1]-a[i-1]-1; k++)

                    b[j++]=a[i-1]+k;
            }
            else
            {
                b[j++]=a[i];
            }
            i++;
        }
    }
    b[j]='\0';
    printf("%s\n",b);
    return 0;
}



