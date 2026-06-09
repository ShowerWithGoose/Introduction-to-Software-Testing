/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-04-07 20:41:27
 * @LastEditors:
 * @LastEditTime: 2022-04-08 17:39:44
 * @FilePath: \Code\line.c
 * @CopyRight:  Â©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lin {
  int ax;
  int ay;
  int bx;
  int by;
  int num;
};
struct lin *lines, *p;
int compar(const void *a, const void *b) {
  return (((struct lin *)a)->ax - ((struct lin *)b)->ax);
}
int main() {

  int n = 0, axmax = 0, aymax = 0, lenm = 1;
  scanf("%d", &n);
  lines = (struct lin *)malloc(sizeof(struct lin) * n);
  p = lines;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &(p->ax), &(p->ay), &(p->bx), &(p->by));
    p->num = 1;
    p++;
  }
  qsort(lines, n, sizeof(lines[0]), compar);
  for (int i = 0; i < n; i++) {
    int len = 1;
    if (lines[i].num == 0) {
      continue;
    }

    for (int h = i + 1; h < n; h++) {

      if (lines[i].ax < lines[h].ax) {
        if (lines[i].bx == lines[h].ax && lines[i].by == lines[h].ay) {
          lines[i].bx = lines[h].bx;
          lines[i].by = lines[h].by;
          lines[i].num++;
          lines[h].num = 0;
          len++;
        }
      }
    }
    if (len > lenm) {
      lenm = len;
      axmax = lines[i].ax;
      aymax = lines[i].ay;
    }
  }
  free(lines);
  printf("%d %d %d", lenm, axmax, aymax);

  return 0;
}


