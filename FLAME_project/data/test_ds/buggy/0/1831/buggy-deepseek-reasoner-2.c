#include<stdio.h>
#include<math.h>
#include<string.h>

int main() {
    char zifu[1001];
    fgets(zifu, sizeof(zifu), stdin);
    int i = 0;
    while (zifu[i] != '\0') {
        if (zifu[i] == '-' && i > 0 && zifu[i+1] != '\0') 
        {
            char tou = zifu[i-1];
            char wei = zifu[i+1];
            if ((tou >= 'a' && tou <= 'z' && wei >= 'a' && wei <= 'z' && wei > tou) || 
                (tou >= 'A' && tou <= 'Z' && wei >= 'A' && wei <= 'Z' && wei > tou) || 
                (tou >= '0' && tou <= '9' && wei >= '0' && wei <= '9' && wei > tou)) {
                for (char c = tou+1; c < wei; c++) {
                    printf("%c", c);
                }
            } // @@ Missing else clause to print the '-' when expansion condition fails
        } 
        else 
        {
            printf("%c", zifu[i]);
        }
        i++;
    }
    return 0;
}