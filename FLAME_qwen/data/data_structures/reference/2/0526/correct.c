#include <stdio.h>
#include <string.h>
int main()
{ int a=0,b=0,c=0;
char x='+',y,z;
while(x!='='){
    scanf("%d%c",&b,&y);
    for(;y==' ';scanf("%c",&y));
    while(y=='*'||y=='/'){
        scanf("%d%c",&c,&z);
        for(;z==' ';scanf("%c",&z));
        if(y=='*')
            b=b*c;
        else if(y=='/')
            b=b/c;
            y=z;
    }
        if(x=='+')
            a=a+b;
        else
            a=a-b;
        x=y;
    }
printf("%d",a);
    return 0;
}




