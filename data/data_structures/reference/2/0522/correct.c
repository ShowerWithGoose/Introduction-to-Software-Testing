#include<stdio.h>
int main()
{
    int a1=0,a2,a3;
    char x1='+',x2,x3;
    for(;x1!='=';){
        scanf("%d %c",&a2,&x2);
        while(x2=='*'||x2=='/'){
            scanf("%d %c",&a3,&x3);
            if(x2=='*')
                a2=a2*a3;
            else
                a2=a2/a3;
            x2=x3;
        }
        if(x1=='+')
            a1=a1+a2;
        if(x1=='-')
            a1=a1-a2;
        x1=x2;
    }
    printf("%d",a1);
    return 0;
}



