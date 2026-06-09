#include <stdio.h>

//滚动数组
int main() {
    int a = 0, b, c;
    char opa = '+', opb, opc;
    while (opa != '=') {
        scanf("%d %c", &b, &opb);
        
        while (opb == '*' || opb == '/') {
            scanf("%d %c", &c, &opc);
            b = (opb=='*') ? (b*c) : (b/c);
            opb = opc;
        }
        a = (opa=='+') ? (a+b) : (a-b);
        opa = opb;
    }
    printf("%d\n", a);
    return 0;
}





