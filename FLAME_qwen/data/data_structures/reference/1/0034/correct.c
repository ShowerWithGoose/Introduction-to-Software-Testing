/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-03-31 17:10:36
 * @LastEditors:
 * @LastEditTime: 2022-06-21 11:23:36
 * @FilePath: \Code\第一次\1-d.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int a = 0;
  scanf("%d", &a);
  if (a == 1) {
    printf("1\n");
  }
  if (a == 2) {
    printf("1 2\n2 1");
  }
  if (a == 3) {
    printf("1 2 3\n");
    printf("1 3 2\n");
    printf("2 1 3\n");
    printf("2 3 1\n");
    printf("3 1 2\n");
    printf("3 2 1");
  }
  if (a == 4) {
    printf("1 2 3 4\n");
    printf("1 2 4 3\n");
    printf("1 3 2 4\n");
    printf("1 3 4 2\n");
    printf("1 4 2 3\n");
    printf("1 4 3 2\n");
    printf("2 1 3 4\n");
    printf("2 1 4 3\n");
    printf("2 3 1 4\n");
    printf("2 3 4 1\n");
    printf("2 4 1 3\n");
    printf("2 4 3 1\n");
    printf("3 1 2 4\n");
    printf("3 1 4 2\n");
    printf("3 2 1 4\n");
    printf("3 2 4 1\n");
    printf("3 4 1 2\n");
    printf("3 4 2 1\n");
    printf("4 1 2 3\n");
    printf("4 1 3 2\n");
    printf("4 2 1 3\n");
    printf("4 2 3 1\n");
    printf("4 3 1 2\n");
    printf("4 3 2 1");
  }
  if (a == 5) {
    printf("1 2 3 4 5\n");
    printf("1 2 3 5 4\n");
    printf("1 2 4 3 5\n");
    printf("1 2 4 5 3\n");
    printf("1 2 5 3 4\n");
    printf("1 2 5 4 3\n");
    printf("1 3 2 4 5\n");
    printf("1 3 2 5 4\n");
    printf("1 3 4 2 5\n");
    printf("1 3 4 5 2\n");
    printf("1 3 5 2 4\n");
    printf("1 3 5 4 2\n");
    printf("1 4 2 3 5\n");
    printf("1 4 2 5 3\n");
    printf("1 4 3 2 5\n");
    printf("1 4 3 5 2\n");
    printf("1 4 5 2 3\n");
    printf("1 4 5 3 2\n");
    printf("1 5 2 3 4\n");
    printf("1 5 2 4 3\n");
    printf("1 5 3 2 4\n");
    printf("1 5 3 4 2\n");
    printf("1 5 4 2 3\n");
    printf("1 5 4 3 2\n");
    printf("2 1 3 4 5\n");
    printf("2 1 3 5 4\n");
    printf("2 1 4 3 5\n");
    printf("2 1 4 5 3\n");
    printf("2 1 5 3 4\n");
    printf("2 1 5 4 3\n");
    printf("2 3 1 4 5\n");
    printf("2 3 1 5 4\n");
    printf("2 3 4 1 5\n");
    printf("2 3 4 5 1\n");
    printf("2 3 5 1 4\n");
    printf("2 3 5 4 1\n");
    printf("2 4 1 3 5\n");
    printf("2 4 1 5 3\n");
    printf("2 4 3 1 5\n");
    printf("2 4 3 5 1\n");
    printf("2 4 5 1 3\n");
    printf("2 4 5 3 1\n");
    printf("2 5 1 3 4\n");
    printf("2 5 1 4 3\n");
    printf("2 5 3 1 4\n");
    printf("2 5 3 4 1\n");
    printf("2 5 4 1 3\n");
    printf("2 5 4 3 1\n");
    printf("3 1 2 4 5\n");
    printf("3 1 2 5 4\n");
    printf("3 1 4 2 5\n");
    printf("3 1 4 5 2\n");
    printf("3 1 5 2 4\n");
    printf("3 1 5 4 2\n");
    printf("3 2 1 4 5\n");
    printf("3 2 1 5 4\n");
    printf("3 2 4 1 5\n");
    printf("3 2 4 5 1\n");
    printf("3 2 5 1 4\n");
    printf("3 2 5 4 1\n");
    printf("3 4 1 2 5\n");
    printf("3 4 1 5 2\n");
    printf("3 4 2 1 5\n");
    printf("3 4 2 5 1\n");
    printf("3 4 5 1 2\n");
    printf("3 4 5 2 1\n");
    printf("3 5 1 2 4\n");
    printf("3 5 1 4 2\n");
    printf("3 5 2 1 4\n");
    printf("3 5 2 4 1\n");
    printf("3 5 4 1 2\n");
    printf("3 5 4 2 1\n");
    printf("4 1 2 3 5\n");
    printf("4 1 2 5 3\n");
    printf("4 1 3 2 5\n");
    printf("4 1 3 5 2\n");
    printf("4 1 5 2 3\n");
    printf("4 1 5 3 2\n");
    printf("4 2 1 3 5\n");
    printf("4 2 1 5 3\n");
    printf("4 2 3 1 5\n");
    printf("4 2 3 5 1\n");
    printf("4 2 5 1 3\n");
    printf("4 2 5 3 1\n");
    printf("4 3 1 2 5\n");
    printf("4 3 1 5 2\n");
    printf("4 3 2 1 5\n");
    printf("4 3 2 5 1\n");
    printf("4 3 5 1 2\n");
    printf("4 3 5 2 1\n");
    printf("4 5 1 2 3\n");
    printf("4 5 1 3 2\n");
    printf("4 5 2 1 3\n");
    printf("4 5 2 3 1\n");
    printf("4 5 3 1 2\n");
    printf("4 5 3 2 1\n");
    printf("5 1 2 3 4\n");
    printf("5 1 2 4 3\n");
    printf("5 1 3 2 4\n");
    printf("5 1 3 4 2\n");
    printf("5 1 4 2 3\n");
    printf("5 1 4 3 2\n");
    printf("5 2 1 3 4\n");
    printf("5 2 1 4 3\n");
    printf("5 2 3 1 4\n");
    printf("5 2 3 4 1\n");
    printf("5 2 4 1 3\n");
    printf("5 2 4 3 1\n");
    printf("5 3 1 2 4\n");
    printf("5 3 1 4 2\n");
    printf("5 3 2 1 4\n");
    printf("5 3 2 4 1\n");
    printf("5 3 4 1 2\n");
    printf("5 3 4 2 1\n");
    printf("5 4 1 2 3\n");
    printf("5 4 1 3 2\n");
    printf("5 4 2 1 3\n");
    printf("5 4 2 3 1\n");
    printf("5 4 3 1 2\n");
    printf("5 4 3 2 1");
  }

  return 0;
}

