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
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                if (a[j-1] < a[j+1]) { // @@ The problem requires expansion only when the character after '-' is greater than the one before. The original code expands even if a[j-1] >= a[j+1] (though the loop condition k < diff handles diff <= 0 by not looping, it's safer to explicitly check or ensure logic matches "greater than"). More importantly, the current logic prints characters inside the if block for '-', but also prints them in the previous if block if they are not '-'. Wait, the structure is: if not '-', print. if is '-', check expansion. If expansion valid, print intermediate chars. This logic is actually mostly correct for printing stream. However, there is a subtle issue.
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
                }
            }
        }
    }
return 0;
}