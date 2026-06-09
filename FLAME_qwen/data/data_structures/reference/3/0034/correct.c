/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-03-15 16:43:56
 * @LastEditors:
 * @LastEditTime: 2022-03-15 17:46:10
 * @FilePath: \Code\notation.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void del0(char s[]) {
  int h = strlen(s);
  int i = 1;
  while (s[h - i] == '0') {
    s[h - i] = '\0';
    i++;
  }
}
int add0(char s[]) { //.后的0数量
  int i = 0;
  char *p = strstr(s, ".");
  while (*(p + i + 1) == '0') {
    i++;
  }
  return i;
}

int main() {
  char s[1000];
  char *p;
  char f[1000];
  int ee = 0;
  gets(s);
  p = strchr(s, '.');
  del0(s);

  if (p == s + 1 && *(p - 1) != '0') {
    printf("%s%s\n", s, "e0");
  }
  if (p == s + 1 && *(p - 1) == '0') {
    int sum0 = add0(s);

    f[0] = *(p + sum0 + 1);
    if (*(p + sum0 + 2) != '\0') {
      f[1] = '.';
    }
    strcat(f, p + sum0 + 2);
    ee = sum0 + 1;
    printf("%s%c%d\n", f, 'e', -ee);
  }

  if (p - s > 1) {
    f[0] = s[0];
    f[1] = '.';
    for (int kk = 0; kk < p - s - 1; kk++) {
      f[2 + kk] = s[kk + 1];
    }
    strcat(f, p + 1);
    ee = p - s - 1;
    printf("%s%c%d\n", f, 'e', ee);
  }

  return 0;
}


