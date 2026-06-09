#include<stdio.h>
#include<string.h>
int main()
{
char a[10010];
char b[10010];
int i,j,k=0,m=0,n;
scanf("%s",a);
if(a[0]=='0'&&a[1]=='.')
{
for(i=0;i<strlen(a);i++)
{
if(a[i]!='0'&&a[i]!='.'&&k==0)
{
k=i;
j=i;
for(;a[j]!='\0';j++)
{b[m]=a[j];
m++;
}
}
else continue;
}
b[m]='\0';
if(b[0]==0||b[1]=='\0')printf("%se-%d",b,k-1);
else {
    printf("%c.",b[0]);
    for(i=1;i<strlen(b);i++)
        printf("%c",b[i]);
printf("e-%d",k-1);
}
}
else
{
    for(i=0;i<strlen(a);i++)
    {

        if(a[i]!='.')
        {

            b[m]=a[i];
            m++;
        }
        else {
            k=i;
        }
    }
    b[m]='\0';
    printf("%c.",b[0]);
    for(i=1;i<strlen(b);i++)
    {

        printf("%c",b[i]);
    }
    printf("e%d",k-1);

}


return 0;
}

