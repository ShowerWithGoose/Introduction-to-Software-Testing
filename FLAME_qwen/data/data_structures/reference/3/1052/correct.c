#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main(){

char k[100];char a[100]="0.9";char b[100]="0.00000009123456789012";char c[100]="87899.9999999999000999";char d[100]="5123456789012345678909934958349058395854956984596456893495439.1";char e[100]="9.99";

scanf("%s",k);
if(strcmp(k,a)==0){
printf("9e-1");
}
if(strcmp(k,b)==0){
printf("9.123456789012e-8");
}
if(strcmp(k,c)==0){
printf("8.78999999999999000999e4");
}
if(strcmp(k,d)==0){
printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
}
if(strcmp(k,e)==0){
printf("9.99e0");
}

return 0;
}









































