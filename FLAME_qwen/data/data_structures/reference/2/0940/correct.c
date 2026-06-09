#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
int a=0,b,c;
char o='+',p,q;
while(o!='='){
        scanf("%d %c",&b,&p);
while(p=='*'||p=='/'){
    scanf("%d %c",&c,&q);
    if(p=='*')
        b=b*c;
    else if(p=='/')
        b=b/c;
    p=q;
}
if(o=='+'){
    a=a+b;
}
else if(o=='-'){
    a=a-b;
}
o=p;
}
printf("%d",a);
return 0;
}



