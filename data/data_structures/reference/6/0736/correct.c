#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int read() {
    int s=0,k=1;char ch;
    while(!isdigit(ch=getchar())) if(ch=='-') k=-1;
    while(isdigit(ch)) {s=s*10+ch-'0', ch=getchar();}
    return s*k;
}


int main() {
    int stk[200], top = 0;
    int opt;
    while((opt=read())!=-1) {
        if(opt) {
            if(top<100) {
                stk[++top] = read();
            } else {
                printf("error "); read();
            }
        }else {
            if(top) {
                printf("%d ",stk[top--]);
            }else {
                printf("error ");
            }
        }
    }
    return 0;
}


// 1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1


