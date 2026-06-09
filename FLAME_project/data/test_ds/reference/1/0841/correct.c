#include <stdio.h>
#include <string.h>
int main(void){
    char c[1000];
    gets(c);
    int len = strlen(c);
    for(int i = 0;i < len;){
        if(c[i] == '-'){
            if((c[i - 1] >= 'a' && c[i + 1] <= 'z')||(c[i - 1] >= 'A' && c[i + 1] <= 'Z')||(c[i - 1] >= '0' && c[i + 1] <= '9')){
                int x = c[i + 1] - c[i - 1];
                if(x > 0){
                    for(int j = 1 ;j <= x ; j++ ){
                        printf("%c",c[i - 1] + j);
                    }
                    if(x == 0){
                        printf("%c",c[i]);
                        i++;
                        continue;
                    }

                    i += 2;
                    continue;
                }
            }
        }
        printf("%c",c[i]);
        i++;
    }
    return 0;
}
