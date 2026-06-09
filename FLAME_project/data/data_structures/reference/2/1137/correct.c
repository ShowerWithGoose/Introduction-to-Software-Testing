#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int op(char a, int l, int r)
{
    switch (a)
    {
    case '+':
        return l + r;
    case '-':
        return l - r;
    case '*':
        return l * r;
    case '/':
        return l / r;
    }
}

int main()
{
    int i=0,b[3]={0};
    char a[2]={'+'};
    scanf("%d",&b[1]);
    while (scanf(" %c",&a[1])!=EOF)
    {
       i++;
       if (a[1]=='=')
       
        break;
       
       scanf(" %d",&b[2]);
       if ((a[0]== '*') || (a[0] == '/') || (a[1]== '+') || (a[1]== '-'))
       {
        b[0]=op(a[0],b[0],b[1]);
        b[1]=b[2];
        a[0]=a[1];
       }
       else {b[1]=op(a[1],b[1],b[2]);}
       
    }
    printf("%d",op(a[0],b[0],b[1]));

    
    return 0;
}
