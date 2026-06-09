#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[10000000];

int main()
{
    gets(a);
    int n = strlen(a);
    for(int i = 0; i < n; i++){
        if(a[i] == '-' && i != 0){
            int t1 = a[i-1], t2 = a[i+1];
            if(t1 >= 'a' && t2 <= 'z' || t1 >= 'A' && t2 <= 'Z' || t1 >= '0' && t2 <= '9'){
                for(int j = t1+1; j < t2; j++){
                    printf("%c", j);
                }
            }
            else{
                printf("-");
            }
        }
        else{
            printf("%c", a[i]);
        }
    }
    return 0;
}

