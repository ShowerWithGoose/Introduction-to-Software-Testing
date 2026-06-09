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
} // @@ [The function 'panduan' is declared to return an int but does not return a value in all control paths. When none of the conditions are met, the function falls through without returning anything, leading to undefined behavior. This may cause runtime errors or incorrect logic, though it typically does not cause a compilation error with some compilers unless strict warnings are enabled. However, given the context and the reference program, this missing return statement is a logical/semantic error that must be fixed by adding 'return 0;' at the end.]