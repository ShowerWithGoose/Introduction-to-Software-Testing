#include<stdio.h>
#include<string.h>
	int a[3];
    char b[2];
int count(int a, int b, char c)
{
    if(c=='*')
        a=a*b;
    else if(c=='/')
        a=a/b;
    else if(c=='+')
        a=a+b;
    else if(c=='-')
        a=a-b;
    return a;
}
int main()
{
	int a[3];
	char b[2];
    scanf("%d",&a[0]);
    scanf("%c",&b[0]);
    while(b[0]==' ')
        scanf("%c",&b[0]);
    if(b[0]!='=')
        scanf("%d",&a[1]);
    while(b[0]!='=')
    {
        if(b[0]=='*'||b[0]=='/')
        {
            a[0]=count(a[0], a[1], b[0]);
            scanf("%c",&b[0]);
            while(b[0]==' ')
                scanf("%c",&b[0]);
            scanf("%d",&a[1]);
        }
        else
        {
            scanf("%c",&b[1]);
            while(b[1]==' ')
                scanf("%c",&b[1]);
            if(b[1]!='=')
            scanf("%d",&a[2]);
            if(b[1]=='+'||b[1]=='-')
            {
                a[0]=count(a[0], a[1], b[0]);
                b[0]=b[1];
                a[1]=a[2];
            }
            else if(b[1]!='=')
                a[1]=count(a[1], a[2], b[1]);
            else
            {
                a[0]=count(a[0], a[1], b[0]);
                b[0]=b[1];
            }
        }
    }
    printf("%d\n",a[0]);
    return 0;
}



