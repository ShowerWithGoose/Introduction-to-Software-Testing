#include<stdio.h>
#include<string.h>
int main()
{
 char a[10005];
 gets(a);
 int m = strlen(a), q = 0, i, n;
 for (i = 0; i < m; i++) {
  if (a[i + 1] != '-'||i==m-1) { printf("%c", a[i]); continue; }
  if (((a[i] >= 'a') && (a[i] <= a[i + 2]) && (a[i + 2] <= 'z')) || ((a[i] >= 'A') && (a[i] <= a[i + 2]) && (a[i + 2] <= 'Z')) || ((a[i] >= '0') && (a[i] <= a[i + 2]) && (a[i + 2] <= '9'))) {
   for (n=a[i];n<a[i+2];n++) printf("%c", n);
   i++;
   continue;
  }
  printf("%c-", a[i++]);
 }
 return 0;
}

