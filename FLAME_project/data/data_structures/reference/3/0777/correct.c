#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int main() {
 char p[1000];
 gets(p);
 int l = strlen(p);
 int dot=l, valid;
 while (p[l - 1]=='0') l--;
 int i;
 for (i = l-1; i>=0; i--) {
  if (p[i] == '.') dot = i;
  if (p[i] > '0' && p[i] <= '9') valid = i;
 }
 printf("%c", p[valid]);
 if (valid < l - 1) printf(".");
 for (i = valid + 1; i < l; i++) if (p[i] >= '0' && p[i] <= '9') printf("%c", p[i]);
 printf("e");
 if (dot < valid) printf("%d", dot - valid);
 else printf("%d", dot - valid - 1);
 return 0;
}

