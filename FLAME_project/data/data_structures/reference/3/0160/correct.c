//
//  main.c
//  小数形式与科学技术法转换
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char a[100];
    int r,p=1,q=-1,flag=0;
    gets(a);
    r=strlen(a);
    if (a[0]>'0') {
        for (int i=0; i<r; i++) {
            if (a[i]!='.')
                q++;
            else {flag=1;break;}
        }
        if (flag==1) {
            printf("%c.",a[0]);
            for (int i=1; i<q+1; i++) {
                printf("%c",a[i]);
            }
            for (int j=q+2; j<r; j++) {
                printf("%c",a[j]);
            }
        }
        else{
            printf("%c.",a[0]);
            for (int i=1; i<q+1; i++) {
                printf("%c",a[i]);
            }}
        printf("e%d",q);
    }
    else if(a[0]=='0'&&a[1]=='.'){
        for (int i=2; i<r; i++) {
            if (a[i]=='0') {
                p++;
            }
            else if(a[i]!='0')
                break;
        }
        if (p+2==r) {
            printf("%ce-%d",a[p+1],p);
        }
        else{
            printf("%c.",a[p+1]);
            for (int j=p+2; j<r; j++) {
                printf("%c",a[j]);
            }
            printf("e-%d",p);
        }
    }
    else printf("%c",a[0]);
    return 0;
}

