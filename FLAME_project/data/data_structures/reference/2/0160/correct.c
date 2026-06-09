//
//  main.c
//  表达式计算
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int a[100]={0},r,p=0,q=0;
    char b[200],c='+';
    gets(b);
    r=strlen(b);
    for (int i=0; i<r; i++) {
        if (b[i]<='9'&&b[i]>='0')
            a[p]=a[p]*10+b[i]-'0';
        else {
            if(b[i]==' ')
                continue;
            else{
                b[q]=b[i];
                q++;
            }
            p++;
        }
    }
    for (int i=0; i<q; i++) {
        if (b[i]=='+'||b[i]=='-') {
            c=b[i];
        }
        else if (b[i]=='*') {
            a[i+1]=a[i]*a[i+1];
            a[i]=0;
            b[i]=c;
        }
        else if(b[i]=='/') {
            a[i+1]=a[i]/a[i+1];
            a[i]=0;
            b[i]=c;
        }
    }
    for (int i=0; i<q; i++) {
        if (b[i]=='+') {
            a[0]=a[i+1]+a[0];
        }
        else
            a[0]=a[0]-a[i+1];
    }
    printf("%d",a[0]);
    return 0;
}



