#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[1000];
char ans[1000];

int main()
{
    gets(a);
    int n = strlen(a);
    int is = 0;
    int point = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '.'){
            is = 1;
            point = i;
            break;
        }
    }
    if(is == 0){
        printf("%se%d", a, n-1);
    }
    else{
        if(point != 1 || (point == 1 && a[0] != '0')){
            for(int i = point-1; i > 0; i--){
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
            printf("%se%d", a, point-1);
        }
        else{
            int i;
            for(i = 2; a[i] == '0'; i++);
            printf("%c", a[i]);
            if(i != n-1) printf(".");
            printf("%se%d", a+i+1, point-i);
        }
    }
    return 0;
}

