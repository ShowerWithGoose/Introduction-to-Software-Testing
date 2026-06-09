#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[105];
int main()
{
    int i, j, k, count = 0, ans = 0;
    gets(str);
    for(i = 0;i < strlen(str);i++ ){
        if(str[i] != '.')
            count++;
        else break;
    }
    if(count > 1){
        printf("%c.", str[0]);
        for(j = 1;j <count;j++){
            printf("%c", str[j]);
        }
        for(j = count + 1;j<strlen(str);j++){
            printf("%c", str[j]);
        }
        printf("e%d", count - 1);

    }

    else if(count = 1){
        if(str[0] >= '1'&&str[0] <= '9'){
            for(j = 0;j < strlen(str);j++){
                printf("%c", str[j]);
            }
            printf("e0\n");
        }
        if(str[0] == '0'){
                j = 2;
            while(str[j] == '0' ){
                j++;
            }
            if(j == strlen(str) - 1){
                printf("%c",str[j]);
                printf("e-%d\n", j - 1);
            }
            else if(j != strlen(str) - 1)
            {
                printf("%c.", str[j]);
                    for(k = j + 1;k < strlen(str);k++){
                        printf("%c", str[k]);
                    }
                printf("e-%d\n", j - 1);
            }
        }
    }

    return 0;
}

