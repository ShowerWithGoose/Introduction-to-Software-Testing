#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
int main(){
    int i=0;
    char ch;
    char a[256]={0};
    while((ch=getchar())!='\n'){
        a[i]=ch;
        i++;
    }
    printf("%c",a[0]);
    for(int j=1;j<i;j++){
        if('-'!=a[j]){
            printf("%c",a[j]);
        }
        if('-'==a[j]){
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){ // @@ Missing check that a[j-1] < a[j+1]; should also require the left character to be smaller than the right one for expansion to occur.
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            } // @@ Missing else clause: when the condition above is false (e.g., different types or start >= end), the dash should be printed as is. Without printing, the dash is lost.
        }
    }
return 0;
}