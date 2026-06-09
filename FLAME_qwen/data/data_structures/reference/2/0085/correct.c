#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char in_put[100] = {'\0'};
    char op_data[2][30] = {{'\0'}};
    int num_data[30] = {0};
    int i = 0, j = 0, pd = 0, m = 0;
    int result = 0;
    gets(in_put);
    for (i = 0; i < strlen(in_put); i++) {
        if (in_put[i] == ' ') {
            for (j = 0; in_put[i + j] != '\0'; j ++) {
                in_put[i + j] = in_put[i + j + 1];
            }
        }
    }
    //strcpy(mid_data[0], in_put);
    for (i = 0, j = 0; i < strlen(in_put); i ++) {
        if (in_put[i] >= '0' && in_put[i] <= '9') {
            for ( ; in_put[i] >= '0' && in_put[i] <= '9'; i ++) {
                num_data[j] = num_data[j] * 10 + in_put[i] - '0';
            }
            j ++;
        }
        if ((in_put[i] >= 42 && in_put[i] <= 45) || in_put[i] == '=' || in_put[i] == '/') {
            op_data[0][m] = in_put[i];
            m ++;
        }
    }
    //do {
    //    pd = 0;
        for (i = 0; op_data[0][i] != '\0'; i ++) {
            if ((op_data[0][i] == '*' || op_data[0][i] == '/') && op_data[1][i] != 1){
                pd = 1;
                for (j = 0; op_data[0][i + j] == '*' || op_data[0][i + j] == '/'; j ++) {
                    if (op_data[0][i + j] == '*') {
                        num_data[i] *= num_data[i + j + 1];
                        op_data[1][i + j] = 1;
                    }
                    else {
                        num_data[i] /= num_data[i + j + 1];
                        op_data[1][i + j] = 1;
                    }
                }
            }
        }
    //} while (pd != 0);
    for (i = 0; op_data[0][i] != '='; i ++) {
        if (op_data[0][i] == '+') {
            num_data[0] += num_data[i + 1];
            op_data[1][i] = 1;
        }
        else if (op_data[0][i] == '-') {
            num_data[0] -= num_data[i + 1];
            op_data[1][i] = 1;
        }
    }
    
    printf("%d", num_data[0]);
    return 0;
}
