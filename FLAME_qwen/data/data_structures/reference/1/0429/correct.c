#include <stdio.h>
#include <string.h>
int main(){
    int n, a1, a2, a3, a4, a5, i;
    scanf("%d", &n);
    if(n == 1)printf("1");
    if(n == 2)printf("1 2\n2 1");
    if(n == 3)printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    if(n == 4)printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1 \n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");
    if(n == 5)for(int k = 1; k <= 54321; k++){
        i = k;
        a5 = i % 10;i /= 10;
        a4 = i % 10;i /= 10;
        a3 = i % 10;i /= 10;
        a2 = i % 10;i /= 10;
        a1 = i % 10;i /= 10;
        if(a1 > 5 || a1 == 0)continue;
        if(a2 > 5 || a2 == 0)continue;
        if(a3 > 5 || a3 == 0)continue;
        if(a4 > 5 || a4 == 0)continue;
        if(a5 > 5 || a5 == 0)continue;
        if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5)continue;
        if(a2 == a3 || a2 == a4 || a2 == a5 || a1 == a5)continue;
        if(a3 == a4 || a3 == a5 || a1 == a4 || a1 == a5)continue;
        if(a1 == a2 || a1 == a3 || a1 == a4 || a4 == a5)continue;
        if(a1 == a2 || a1 == a3 || a1 == a4 || a1 == a5)continue;
        printf("%d %d %d %d %d\n", a1, a2, a3, a4, a5);
    }
    scanf("%d", &a1);
}




