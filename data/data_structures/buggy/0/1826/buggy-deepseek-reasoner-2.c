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
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){ // @@ Missing condition: a[j+1] > a[j-1] must be checked to ensure expansion only when the character after the dash is greater. Also, a[j+1] might be out of bounds when j is the last index (j=i-1), leading to undefined behavior or incorrect failure.
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            } // @@ Missing else clause: When the expansion condition fails, the dash itself should be printed. Currently, it is silently omitted, causing missing characters in the output.
        }
    }
return 0;
}