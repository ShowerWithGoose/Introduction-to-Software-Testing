/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-03-16 13:19:51
 * @LastEditors:
 * @LastEditTime: 2022-03-16 14:41:59
 * @FilePath: \Codec:\Users\\Desktop\expand.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expa(int k, int j) {
  int c = k;
  while (c < j - 1) {
    printf("%c", c + 1);
    c++;
  }
}
int panduan(int k, int j) {
  if (k > j) {
    return 0;
  }
  if ((k >= 'a' && k <= 'z') && j >= 'a' && j <= 'z') {
    return 1;
  }
  if ((k >= 'A' && k <= 'Z') && j >= 'A' && j <= 'Z') {
    return 1;
  }
  if ((k >= '0' && k <= '9') && j >= '0' && j <= '9') {
    return 1;
  }
  return 0;
}
int main() {
  char *o[100];
  char s[100];
  char *p, *q, *m;
  int i = 1;
  gets(s);
  p = s;
  o[0] = s;
  for (int h = 0; h < strlen(s); h++) {
    if (*(s + h) == '-') {
      o[i] = s + h;
      i++;
    }
  }
  o[i] = s + strlen(s) - 1;
  for (int h = 1; h < i; h++) {
    if (h != 1) {
      m = o[h - 1] + 1;
    } else {
      m = o[h - 1];
    }

    p = o[h];

    q = o[h + 1];

    for (int y = 0; y <= p - m - 1; y++) {
      printf("%c", *(m + y));
    }
    if (panduan(*(p - 1), *(p + 1)) == 1) {
      expa(*(p - 1), *(p + 1));
      if (h == i - 1) {
        printf("%c", *(p + 1));
      }
    } else {
      for (int y = 0; y <= q - p; y++) {
        printf("%c", *(p + y));
      }
    }
  }

  // puts(s);

  return 0;
}


