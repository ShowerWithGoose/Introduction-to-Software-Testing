#include<stdio.h>
int main(){
int a1=0,a2=0,a3=0;
char b1,b2,b3;
b3='+';
while(1){
scanf("%d %c",&a1,&b1);
while(b1=='*'||b1=='/'){
 scanf("%d %c",&a2,&b2);
 if(b1=='*')
 a1=a1*a2;
 else if(b1=='/')
 a1=a1/a2;
 b1=b2;
 }
if(b3=='+')
a3+=a1;
else if(b3=='-')
a3-=a1;
b3=b1;
if(b3=='='){
printf("%d",a3);
break;}
}
return 0;
}

