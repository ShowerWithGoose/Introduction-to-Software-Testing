#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
   char a[1000];
   gets(a);
   int x=strlen(a);
   int i,j,t,k=0;
   for(i=1;i<x-1;i++){
    int f=0;
    if(a[i]=='-'){
        if(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
            f=1;
        if(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
            f=1;
        if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
            f=1;
    }
    if(f){
        int c=a[i+1]-a[i-1];
        for(j=k;j<i;j++){
            printf("%c",a[j]);
        }
        for(t=1;t<c;t++){
            printf("%c",a[i-1]+t);
        }
        k=i+1;
    }
   }
   for(j=k;j<x;j++){
    printf("%c",a[j]);
   }
   return 0;
}

