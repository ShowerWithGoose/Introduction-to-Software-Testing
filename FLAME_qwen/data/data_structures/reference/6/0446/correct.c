#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
   int i,n=0,l,s[1000]={0},t;
   while(1){
    scanf("%d",&l);
    if(l==1){
            if(n>=100){
                printf("error ");
            }
        else{scanf("%d",&t);
        s[n]=t;
        n++;}
    }
    if(l==0){
        if(n!=0){
                t=s[n-1];
            printf("%d ",t);
            n--;
        }
        else if(n==0){
          printf("error ");
        }
    }
    if(l==-1){
        break;
    }
   }
}

