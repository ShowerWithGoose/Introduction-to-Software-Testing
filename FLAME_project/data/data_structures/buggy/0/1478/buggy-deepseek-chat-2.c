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
if(panduan(a[i], a[i + 2])){
for(c = a[i] +1; c < a[i + 2]; c++)
b[o++] = c;
i++;}}}
b[o] = '\0';


printf("%s",b);
return 0;
}

int panduan(char begen, char end)
{
if (isupper(begen) && isupper(end) && begen < end)return 1;

else if (isdigit(begen) && isdigit(end) && begen < end)return 1;

else if (islower(begen) && islower(end) && begen < end)return 1;
} // @@ Missing return statement for cases where none of the conditions are true; function should return 0 to indicate no expansion.