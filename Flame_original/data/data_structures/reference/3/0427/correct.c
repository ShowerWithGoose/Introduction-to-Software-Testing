#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
   char  a[105];
   gets(a);
   int x=strlen(a);
   int i,n;
   for(i=0;i<x;i++){
        if(a[i]=='.'){
            n=i;
            break;
        }
   }
   if(n==1){
        if(a[0]!='0'){
            for(i=0;i<x;i++){
                printf("%c",a[i]);
            }
            printf("e%d",n-1);
        }
        else{
            int m;
            for(i=2;i<x;i++){
                if(a[i]!='0'){
                    m=i;
                    break;
                }
            }
            printf("%c",a[m]);
            if(m<x-1){
                printf(".");
                for(i=m+1;i<x;i++){
                    printf("%c",a[i]);
                }
            }
            printf("e-%d",m-1);
        }
   }
   if(n>1){
        printf("%c.",a[0]);
        for(i=1;i<x;i++){
            if(a[i]!='.'){
                printf("%c",a[i]);
            }
        }
        printf("e%d",n-1);
   }

   return 0;
}



