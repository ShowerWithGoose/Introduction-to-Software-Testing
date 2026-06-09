//
//  main.c
//  扩展字符
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char a[205];
    int l;
    gets(a);
    l=strlen(a);
    for (int i=0; i<l; i++) {
        if (a[i]!='-') {
            printf("%c",a[i]);
        }
        else if((a[i-1]<='Z')&&(a[i-1]>='A')&&i+1<l){
            if((a[i+1]<='Z')&&(a[i+1]>='A')&&a[i+1]>a[i-1]){
                for (char j=a[i-1]+1; j<a[i+1]; j++) {
                    printf("%c",j);
                }
            }
            else
                printf("-");
        }
        else if((a[i-1]<='z')&&(a[i-1]>='a')&&i+1<l){
            if((a[i+1]<='z')&&(a[i+1]>='a')&&a[i+1]>a[i-1]){
                for (char j=a[i-1]+1; j<a[i+1]; j++) {
                    printf("%c",j);
                }
            }
            else
                printf("-");
        }
        else if((a[i-1]<='9')&&(a[i-1]>='0')&&i+1<l){
            if((a[i+1]<='9')&&(a[i+1]>='0')&&a[i+1]>a[i-1]){
                for (char j=a[i-1]+1; j<a[i+1]; j++) {
                    printf("%c",j);
                }
            }
            else
                printf("-");
        }
    }
    return 0;
}



