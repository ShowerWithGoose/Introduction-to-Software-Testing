#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ward {
    int count;
    char ward[50];
} Ward;

int read(char *s, FILE *fre) {
    char temp;
    while (temp = fgetc(fre)) {
        if (temp == EOF)
            return -1;
        else if (isalpha(temp)) {
            break;
        } else if (!isalpha(temp))
            continue;
    }
    char *c = s;
    *(c++) = tolower(temp);
    while ((temp = fgetc(fre)) != EOF && isalpha(temp)) {
        *(c++) = tolower(temp);
    }
    *c = '\0';
    return 1;
}

int halfSearch(Ward di[500], int n, char *s) {
    int low = 0, high = n - 1, mid = (low + high) / 2;
    while (low <= high) {
        if (strcmp(di[mid].ward, s) == 0) {
            di[mid].count++;
            return -1;
        } else if (strcmp(di[mid].ward, s) > 0) {
            high = mid - 1;
            mid = (low + high) / 2;
        } else {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    return low;
}

int main() {
    Ward dict[500];
    int n = 0;
    char *s = (char *)malloc(50 * sizeof(char));
    FILE *fin = fopen("article.txt", "r");
    read(s, fin);
    strcpy(dict[0].ward, s);
    dict[0].count = 1;
    n++;
    while (read(s, fin) != -1) {
        int p = halfSearch(dict, n, s);
        if (p == -1)
            continue;
        else {
            int i;
            for (i = n - 1; i >= p; i--) {
                dict[i + 1] = dict[i];
            }
            dict[p].count = 1;
            strcpy(dict[p].ward, s);
            n++;
        }
    }
    int i = 0;
    for (; i < n; i++) {
        printf("%s %d\n", dict[i].ward, dict[i].count);
    }
    fclose(fin);
    return 0;
}
