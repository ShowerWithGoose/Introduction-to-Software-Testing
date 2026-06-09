#include <stdio.h>
#include <string.h>
#define LEN 1024
#include <ctype.h>

int panduan(char begen, char end);


int main()
{
char a[100], b[100];
scanf("%s",a);
char c;
int i, o;
for (i = 0, o = 0; a[i] != '\0'; i++){
b[o++] = a[i];
if(a[i + 1] == '-'){
if(panduan(a[i], a[i + 2])){ // @@ [May access out-of-bounds a[i+2] when string ends without a character after '-'; also panduan may not return a value]
for(c = a[i] +1; c < a[i + 2]; c++)
b[o++] = c;
i++;}}} // @@ [Unconditionally increments i when a[i+1]=='-', even when expansion fails, causing the '-' to be lost]
b[o] = '\0';


printf("%s",b);
return 0;
}

int panduan(char begen, char end)
{
if (isupper(begen) && isupper(end) && begen < end)return 1;

else if (isdigit(begen) && isdigit(end) && begen < end)return 1;

else if (islower(begen) && islower(end) && begen < end)return 1;
} // @@ [Missing return statement; function falls off without returning a value if none of the conditions are true]