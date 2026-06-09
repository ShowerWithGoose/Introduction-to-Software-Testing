/*
 * @Course: Data Sturctures And Programming
 * @Teacher:
 * @Date: 2022-04-18 20:56:49
 * @LastEditors:
 * @LastEditTime: 2022-04-18 22:26:53
 * @FilePath: \Code\articlebase.c
 * @CopyRight:  Â©2022 All Rights Reserved
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stor {
  char s[10];
  int num;
  int jud;

} stor;

int compar(const void *a, const void *b) {
  return strcmp(((stor *)a)->s, ((stor *)b)->s);
}

int main() {
  char s[1000];
  stor stt[1000];
  FILE *fw = fopen("article.txt", "r");
  char tmpc = fgetc(fw);
  int i = 0;
  int ann = 0;
  while (tmpc != EOF) {
    if (tmpc >= 65 && tmpc <= 90) {
      tmpc = tmpc + 32;
    }
    if ((tmpc < 65 || tmpc > 122) || (tmpc < 97 && tmpc > 90)) {
      tmpc = ' ';
    }
    s[i] = tmpc;
    tmpc = fgetc(fw);
    i++;
  }
  s[i] = '\0';
  // puts(s);
  for (int h = 0, m = 0, t = 0; h < i; h++) {

    if ((s[h] == ' ' && s[h + 1] == ' ') || (s[h] == ' ' && s[h + 1] != ' ')) {
      stt[m].s[t] = '\0';
      // puts(stt[m].s);

      t = 0;
      m++;
    } else {
      stt[m].s[t] = s[h];
      stt[m].num = 1;
      stt[m].jud = 0;
      t++;
    }
  }
  for (int h = 0; h < i; h++) {
    if (strcmp(stt[h].s, "\0") == 0) {
      strcpy(stt[h].s, "1");
      stt[h].jud = 1;
    }
  }
  i = 0;
  for (int i = 0, m = 0; strcmp(stt[i].s, "\0") != 0; i++) {
    for (m = i + 1; strcmp(stt[m].s, "\0") != 0; m++) {
      if (stt[m].jud == 1) {
        continue;
      }
      if (strcmp(stt[i].s, stt[m].s) == 0) {
        stt[i].num++;
        stt[m].jud = 1;
      }
    }
    ann = i;
  }
  qsort(stt, ann, sizeof(stor), compar);
  for (int i = 0; i < ann; i++) {
    if (stt[i].jud == 1) {
      continue;
    }
    printf("%s %d\n", stt[i].s, stt[i].num);
  }
  fclose(fw);
  return 0;
}


