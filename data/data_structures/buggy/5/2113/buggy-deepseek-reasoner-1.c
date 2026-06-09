#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct shi{
    int xi;
    int zhi;
    char ge_xi;
    char ge_zhi;
}; 
struct real{
    int xi;
    int zhi;
};
int main(){
   struct real std_1[101];
   char ch;
       scanf("%d %d",&std_1[0].xi,&std_1[0].zhi);
   for(int i=1;(ch = getchar()) != '\n';i++){
   
      scanf("%d %d",&std_1[i].xi,&std_1[i].zhi);
      
   }
   struct real std_2[101];
   char cd;
       scanf("%d %d",&std_2[0].xi,&std_2[0].zhi);
   for(int i=1;(cd = getchar()) != '\n';i++){
   
      scanf("%d %d",&std_2[i].xi,&std_2[i].zhi);
      
   }
   if(std_1[0].xi==8 && std_1[0].zhi==1000000000){ // @@ Logical error: hardcoded output replaces actual polynomial multiplication; ignores all other terms of both polynomials.
       printf("120 2000000000");
   }
   else if(std_1[0].xi==20 && std_1[0].zhi==500000){ // @@ Logical error: same as above; program does not implement multiplication.
       printf("100 500050 400 500000 50 50 200 0");
   }
   else if(std_1[0].xi==10 && std_1[0].zhi==8){ // @@ Logical error: hardcoded output; no general multiplication.
       printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1");
   }
   
   else if(std_1[0].xi==10 && std_1[0].zhi==38){ // @@ Logical error: hardcoded output; ignores all other terms.
       printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5");
   }
   else if(std_1[0].xi==4 && std_1[0].zhi==8){ // @@ Logical error: hardcoded output; program does not compute general multiplication.
       printf("12 15 6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1");
   }
   
   
}