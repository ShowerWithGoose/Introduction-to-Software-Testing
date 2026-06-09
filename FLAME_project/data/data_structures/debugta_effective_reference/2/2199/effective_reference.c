#include<stdio.h>
#include<math.h>
int num1,num2,num3;
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
    num1=0;o1='+';
    while(o1!='=')
    {
        scanf("%d %c",&num2,&o2);
        while(o2=='*'||o2=='/')
        {
            scanf("%d %c",&num3,&o3);
            num2=cal(num2,num3,o2);
            o2=o3;
        }
        num1=cal(num1,num2,o1);
        o1=o2;
    }
    printf("%d",num1);
    return 0;
}



