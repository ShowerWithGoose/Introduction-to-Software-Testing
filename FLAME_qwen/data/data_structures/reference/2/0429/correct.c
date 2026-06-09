#include <stdio.h>
#include <string.h>
int main()
{
    char a[10000];
    int num[10000] = {0}, c[10000], sum = 0;
    int len, k = 0 , j, i;
    gets(a);
    len = strlen(a);
    for (i = 0,j = 0; i < len || a[i] == '='; i++){
        while (a[i] == ' ')i++;
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] =='/' ){
            if (a[i] == '+'){
                c[j] = 1;
                j++;
            }
            if (a[i] == '-'){
                c[j] = 2;
                j++;
            }
            if (a[i] == '*'){
                c[j] = 3;
                j++;
            }
            if(a[i] == '/'){
                c[j] = 4;
                j++;
            }
            continue;
        }
        do {
            num[k] = num[k] * 10 + a[i] - '0';
            i++;
        }while (a[i] <= '9' && a[i] >= '0');
        k++;
        i--;
    }

    for (i = 0; i < j; i++){
        if (c[i] == 3){
            num[i+1] = num[i] * num[i+1];
            num[i] = 0;
            if(i == 0)c[i] = 1;
            else c[i] = c[i-1];
        }
        if (c[i] == 4){
            num[i+1] = num[i] / num[i+1];
            num[i] = 0;
            if(i == 0)c[i] = 1;
            else c[i] = c[i-1];
        }
    }
    sum = num[0];
    for (i = 0; i < j; i++){
        if (c[i] == 1){
            sum += num[i+1];
        }
        if (c[i] == 2){
            sum -= num[i+1];
        }
    }
    printf ("%d", sum);
    gets(a);
    return 0;
}


