/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-04-26 18:08:02
 * @LastEditors:
 * @LastEditTime: 2022-06-21 11:25:32
 * @FilePath: \Code\第四次\cal.c
 * @CopyRight:  ©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;
int po = 0;
int num = 0;
typedef struct {
  char h;
  int num;
  int isnum;
} sto;
sto k[100];
void delx(char s[]) {
  char e[100];
  int h = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == ' ') {
      continue;
    } else {
      e[h] = s[i];
      h++;
    }
  }
  e[h] = '\0';
  strcpy(s, e);
}
void pulc(char s[], char h) {
  int chec1 = 0;
  int chec2 = 0;
  if ((s[po - 1] == '*' || s[po - 1] == '/') && po > 0) {
    chec1 = 1;
  }
  if (h == '*' || h == '/') {
    chec2 = 1;
  }
  if (chec1 >= chec2 && po != 0) {
    while (chec1 >= chec2 && po > 0 && s[po - 1] != '(') {
      k[num].isnum = 0;
      k[num].h = s[po - 1];
      num++;
      po--;
      if ((s[po - 1] == '*' || s[po - 1] == '/') && po > 0) {
        chec1 = 1;
      } else {
        chec1 = 0;
      }
    }
    s[po] = h;
    po++;
  } else {
    s[po] = h;
    po++;
  }
}
void polan2(char s[], char h) {
  while (s[po - 1] != '(') {
    k[num].isnum = 0;
    k[num].h = s[po - 1];
    po--;
    num++;
  }
  po--;
}
void in(char s[]) {

  int tmp1[100] = {0};

  char polan[100];
  polan[99] = '\0';

  for (int h = 0; h < strlen(s); h++) {
    if ('0' <= s[h] && s[h] <= '9') {
      tmp1[i] = (int)(s[h] - 48);

      i++;

    } else {
      if (i != 0) {
        for (int m = 0; m < i; m++) {
          k[num].isnum = 1;

          k[num].num += (tmp1[i - m - 1] * pow(10, m));
        }

        num++;
        i = 0;
      }
      if (s[h] == '(') {
        polan[po] = s[h];

        po++;
      }
      if ((s[h] == '+' || s[h] == '-' || s[h] == '/' || s[h] == '*') &&
          po > 0) {
        pulc(polan, s[h]);
      }
      if ((s[h] == '+' || s[h] == '-' || s[h] == '/' || s[h] == '*') &&
          po == 0) {
        polan[po] = s[h];
        po++;
      }
      if (s[h] == ')') {
        polan2(polan, s[h]);
      }
    }
  }
  while (po >= 0) {
    k[num].isnum = 0;
    k[num].h = polan[po - 1];
    po--;
    num++;
  }
}
double jisuan() {
  double tmp[100];
  int f = 0;
  double last = 0;
  for (int o = 0; o < num; o++) {
    if (k[o].isnum == 1) {
      tmp[f] = k[o].num;
      f++;
    }
    if (k[o].isnum == 0) {
      if (k[o].h == '+') {
        double tmmp = 0;
        tmmp = tmp[f - 2] + tmp[f - 1];
        f = f - 2;
        tmp[f] = tmmp;
        f++;
      }
      if (k[o].h == '-') {
        double tmmp = 0;
        tmmp = tmp[f - 2] - tmp[f - 1];
        f = f - 2;
        tmp[f] = tmmp;
        f++;
      }
      if (k[o].h == '*') {
        double tmmp = 0;
        tmmp = tmp[f - 1] * tmp[f - 2];
        f = f - 2;
        tmp[f] = tmmp;
        f++;
      }
      if (k[o].h == '/') {
        double tmmp = 0;
        tmmp = tmp[f - 2] / tmp[f - 1];
        f = f - 2;
        tmp[f] = tmmp;
        f++;
      }
    }
  }
  for (int i = 0; i < f; i++) {
    last += tmp[i];
  }
  return last;
}
int main() {
  char s[10000];
  gets(s);
  delx(s);

  in(s); 
  //  for(int i=0;i<strlen(s);i++){
  //   if(k[i].isnum==0){
  //     printf("%c",k[i].h);
  //   }else{
  //     printf("%d",k[i].num);
  //   }
  // }
  
  printf("\n%d", (int)(jisuan()));
  return 0;
}
