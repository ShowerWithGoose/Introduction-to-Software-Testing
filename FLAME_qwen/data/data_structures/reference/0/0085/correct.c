#include <stdio.h>

int main()
{
    char line_in[100] = {'\0'}, line_out[100] = {'\0'};
    int i = 0, j = 0;
    gets(line_in);
    for(i = 0; line_in[i] != '\0'; i ++) {
        if(line_in[i] != '-') {
            line_out[j] = line_in[i];
            j ++;
        }
        else {
            if (line_in[i - 1] >= 'a' && line_in[i - 1] <= 'z') {
                if (line_in[i + 1] < 'a' || line_in[i + 1] > 'z' || line_in[i + 1] <= line_in[i - 1]) {
                    line_out[j] = line_in[i];
                    j ++;
                    continue;
                }
                else {
                    int m = 1;
                    for (m = 1; line_in[i - 1] + m < line_in[i + 1]; m ++, j ++) {
                        line_out[j] = line_in[i - 1] + m;
                    }
                }
            }
            else if (line_in[i - 1] >= 'A' && line_in[i - 1] <= 'Z') {
                if (line_in[i + 1] < 'A' || line_in[i + 1] > 'Z' || line_in[i + 1] <= line_in[i - 1]) {
                    line_out[j] = line_in[i];
                    j ++;
                    continue;
                }
                else {
                    int m = 1;
                    for (m = 1; line_in[i - 1] + m < line_in[i + 1]; m ++, j ++) {
                        line_out[j] = line_in[i - 1] + m;
                    }
                }
            }
            else if (line_in[i - 1] >= '0' && line_in[i - 1] <= '9') {
                if (line_in[i + 1] < '0' || line_in[i + 1] > '9' || line_in[i + 1] <= line_in[i - 1]) {
                    line_out[j] = line_in[i];
                    j ++;
                    continue;
                }
                else {
                    int m = 1;
                    for (m = 1; line_in[i - 1] + m < line_in[i + 1]; m ++, j ++) {
                        line_out[j] = line_in[i - 1] + m;
                    }
                }
            }
        }
    }
    puts(line_out);
    return 0;
}

