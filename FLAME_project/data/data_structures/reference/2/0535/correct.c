#include<stdio.h>
#include<math.h>
int a1,a2,a3;
char o1,o2,o3;
int cal(int x,int y,char o)
{
    switch(o)
    {
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '*':
        return x*y;
    case '/':
        return x/y;
    }
}
int main()
{
    a1=0;o1='+';
    while(o1!='=')
    {
        scanf("%d %c",&a2,&o2);
        while(o2=='*'||o2=='/')
        {
            scanf("%d %c",&a3,&o3);
            a2=cal(a2,a3,o2);
            o2=o3;
        }
        a1=cal(a1,a2,o1);
        o1=o2;
    }
    printf("%d",a1);
    return 0;
}



