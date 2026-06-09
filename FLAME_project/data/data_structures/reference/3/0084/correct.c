#include<stdio.h>
int main()
{
    char a[101],temp;
    int i,j,x,y;
    gets(a);
    for(i=0;a[i]!='\0'&&a[i]!='.';i++)
        ;
    if(i==1)
    {
        if(a[0]=='0')
        {
            for(j=1,x=0;a[j+1]=='0';j++)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                x++;
            }
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            x++;
            if(a[j+2]!='\0')
            {
                for(y=j;a[y]!='\0';y++)
            {
                printf("%c",a[y]);}
            }
            if(a[j+2]=='\0')
                printf("%c",a[j]);
            printf("e%d",-x);

        }
        if(a[0]!='0')
        {
            for(j=0;a[j]!='\0';j++)
            {
                printf("%c",a[j]);
            }
            printf("e0");
        }
    }
    if(i>1)
    {
        for(y=i,x=0;y>1;y--)
        {
            temp=a[y];
            a[y]=a[y-1];
            a[y-1]=temp;
            x++;
        }
        for(i=0;a[i]!='\0';i++)
            {
                printf("%c",a[i]);
            }
        printf("e%d",x);
    }
    return 0;
}

