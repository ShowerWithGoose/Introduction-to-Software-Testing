#include <stdio.h>
#include <string.h>

#define LEN 100 + 5

char c[LEN];
char temp[LEN];

int main(void) {

    gets(c);

    int i;
    for (i = 0; c[i] != '.'; i++)
        temp[i] = c[i];
    temp[i] = '\0';
    if (strlen(temp) == 1)
        if (temp[0] != '0')
            printf("%se0", c);
        else {
            int flag = 0;
            for (int i = 0; i < strlen(c) - strlen(temp) - 1; i++) {
                flag++;
                if (c[strlen(temp) + i + 1] != '0')
                    break;
            }
                printf ("%c", c[flag + 1]);
            if ((strlen(c) - flag - 1) <= 1)
                printf("e-%d", flag);
            else {
                printf(".");
                for (int k = flag + 2; c[k] != '\0'; k++)
                    printf("%c", c[k]);
                printf("e-%d", flag);
            }
        }
    else{
        printf("%c.", temp[0]);
        for (int i = 1; i < strlen(temp); i++)
            printf("%c", temp[i]);
        for (int j = strlen(temp); c[j] != '\0'; j++) {
            if (j + 1 == strlen(c))
                break;
            printf("%c", c[j + 1]);
        }
            
        printf("e%d", strlen(temp) - 1);
    }
    return 0;
}
