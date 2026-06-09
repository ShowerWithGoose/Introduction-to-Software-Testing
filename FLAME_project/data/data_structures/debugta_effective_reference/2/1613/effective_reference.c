#include<stdio.h>
int main()
{
    int x1=0,x2,x3;
    char a1='+',a2,a3;
    for(;a1!='=';){
        scanf("%d %c",&x2,&a2);
        while(a2=='*'||a2=='/'){
            scanf("%d %c",&x3,&a3);
            if(a2=='*')
                x2=x2*x3;
            else
                x2=x2/x3;
            a2=a3;
        }
        if(a1=='+')
            x1=x1+x2;
        if(a1=='-')
            x1=x1-x2;
        a1=a2;
    }
    printf("%d",x1);
    return 0;
}



